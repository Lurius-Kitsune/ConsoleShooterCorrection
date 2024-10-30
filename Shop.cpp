#include "Shop.h"
#include "WeaponMelee.h"
#include "WeaponRange.h"
#include "WeaponWheel.h"
Shop::Shop()
{
    weapons = new Weapon * [1]
        {
            new WeaponRange("AK-47", "Pan-Pan", BLINK_TEXT  RED, 1000, 12.2f, 10, BT_PARTITION),
        };
    weaponsCount = 1;

    consumables = new Consumable * [4]
        {
            new Consumable(0, CT_MILK),
            new Consumable(0, CT_APPLE),
            new Consumable(0, CT_SPINACH),
            new Consumable(0, CT_WATER)
        };
    consumablesCount = 4;

    bulletsCount = 6;
    bullets = new Bullet * [bulletsCount]
    {
        new Bullet(BT_PARTITION),
            new Bullet(BT_ARROW),
            new Bullet(BT_BOAT_TAIL),
            new Bullet(BT_HOLLOW_POINT),
            new Bullet(BT_JACKETED_HOLLOW_POINT),
            new Bullet(BT_ROUND_NOSE)
    };
}

Shop::~Shop()
{
    for (u_int _i = 0;  _i < weaponsCount;  _i++)
    {
        delete weapons[_i];
    }
    delete[] weapons;

    for (u_int _i = 0; _i < consumablesCount; _i++)
    {
        delete consumables[_i];
    }
    delete[] consumables;

    for (u_int _i = 0; _i < bulletsCount; _i++)
    {
        delete bullets[_i];
    }
    delete[] bullets;
}


/// <summary>
/// Ouvre un magasin
/// </summary>
/// <param name="_purchasables">Purchasable qui vont etre affecter</param>
/// <param name="_purchasablesCount">Le nb d'objet</param>
void Shop::Open(Player* _player)
{
    player = _player;
    const string _shopItemNames[] =
    {
        "Armes",
        "Consomable",
        "Bullet"
    };
    const u_int& _shopItemNamesCount = size(_shopItemNames);
    int _menuIndex;
    do
    {
        CLEAR_SCREEN;
        _menuIndex = OpenMenu(_shopItemNames, _shopItemNamesCount, "Quel magasin accéder ?");
        Purchasable* _purchase;
        if (_menuIndex == 0)
        {
            if(Weapon* _purchase = SellWeapons())
            {
                player->GetWheel()->AddWeapon(_purchase);
            }
        }
        else if (_menuIndex == 1)
        {
            if (Consumable* _purchase = SellConsumable())
            {
                player->GetInventory()->AddConsumable(_purchase);
            }
        }
        else if (_menuIndex == 2)
        {
            if (Bullet* _purchase = SellBullets())
            {
                player->GetInventory()->AddBullet(_purchase);
            }
        }
        else
        {
            break;
        }
    } while (true);
    
    Close();
}

Weapon* Shop::SellWeapons()
{
    string* _weaponsName = GetWeaponsName();
    Weapon* _weapon = nullptr;
    bool _isValidIndex, _containsWeapon;
    WeaponWheel* _wheel = player->GetWheel();
    do
    {
        const int _weaponsIndex = OpenMenu(_weaponsName, weaponsCount, "Que souhaitez-vous acheter comme arme ?");
        CLEAR_SCREEN;
        if (_weaponsIndex == weaponsCount)
        {
            delete[] _weaponsName;
            return nullptr;
        }
        if (_isValidIndex = _weaponsIndex >= 0 && _weaponsIndex < weaponsCount)
        {
            _weapon = weapons[_weaponsIndex];
        }
        if (_containsWeapon = _wheel->ConstainsWeapon(_weapon))
        {
            DISPLAY("Vous posséder déja cette arme !", true);
        }


    } while (!_isValidIndex || _containsWeapon);

    delete[] _weaponsName;
    return _weapon;
}

string* Shop::GetWeaponsName() const
{
    string* _weaponsName = new string[weaponsCount];
    for (u_int _i = 0; _i < weaponsCount; _i++)
    {
        Weapon* _weapon = weapons[_i];
        _weaponsName[_i] = (player->GetWheel()->ConstainsWeapon(_weapon) ?
                STRIKETHROUGH_TEXT + _weapon->GetName() + RESET :
                _weapon->GetSkin() + _weapon->GetName() + RESET);
    }
    return _weaponsName;
}

string* Shop::GetBulletsName() const
{
    string* _newArray = new string[bulletsCount];

    for (u_int _index = 0; _index < bulletsCount; _index++)
    {
        _newArray[_index] = bullets[_index]->GetTypeName();
    }

    return _newArray;
}

Bullet* Shop::SellBullets()
{
    string* _bulletsName = GetBulletsName();
    const u_int& _bulletIndex = OpenMenu(_bulletsName, bulletsCount, "Quelle item souhaitez-vous acheter ?");
    delete[] _bulletsName;

    const bool _isValidIndex = _bulletIndex >= 0 && _bulletIndex < bulletsCount;
    Bullet* _bullet = bullets[_bulletIndex];
    return _isValidIndex ? new Bullet(*_bullet) : nullptr;
}

string* Shop::GetConsumablesName() const
{
    string* _newArray = new string[consumablesCount];
    for (u_int _i = 0; _i < consumablesCount; _i++)
    {
        _newArray[_i] = consumables[_i]->GetTypeName();
    }
    return _newArray;
}

Consumable* Shop::SellConsumable()
{
    string* _consumablesName = GetConsumablesName();
    const int _consumableIndex = OpenMenu(_consumablesName, consumablesCount, "Que souhaitez-vous acheter comme consomable ?");
    delete[] _consumablesName;
    bool _isValidIndex = _consumableIndex >= 0 && _consumableIndex < consumablesCount;
    Consumable* _consumable = consumables[_consumableIndex];
    return _isValidIndex ? new Consumable(*_consumable) : nullptr;
}

void Shop::Close()
{
    player = nullptr;
}
