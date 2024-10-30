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

	purchasableItemsCount = 10;

	purchasableItems = new PurchasableItem * [purchasableItemsCount]
        {
                new Bullet(BT_PARTITION),
                new Bullet(BT_ARROW),
                new Consumable(0, CT_MILK),
                new Consumable(0, CT_APPLE),
                new Bullet(BT_BOAT_TAIL),
                new Bullet(BT_HOLLOW_POINT),
                new Consumable(0, CT_SPINACH),
                new Consumable(0, CT_WATER),
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

	for (u_int _i = 0; _i < purchasableItemsCount; _i++)
	{
		delete purchasableItems[_i];
	}
    delete[] purchasableItems;
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
        if (_containsWeapon = _wheel->ContainsWeapon(_weapon))
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
        _weaponsName[_i] = (player->GetWheel()->ContainsWeapon(_weapon) ?
                STRIKETHROUGH_TEXT + _weapon->GetName() + RESET :
                _weapon->GetSkin() + _weapon->GetName() + RESET);
    }
    return _weaponsName;
}

Bullet* Shop::SellBullets()
{
    u_int _bulletsCount = 0;
    Bullet* _type = new Bullet(BT_ARROW);
    string* _bulletsName = GetPurchasableItemsName(_type, _bulletsCount);
    const u_int& _bulletIndex = OpenMenu(_bulletsName, _bulletsCount, "Quelle item souhaitez-vous acheter ?");
    delete[] _bulletsName;

    const bool _isValidIndex = _bulletIndex >= 0 && _bulletIndex < _bulletsCount;
    Bullet* _bullet = dynamic_cast<Bullet*>(purchasableItems[_bulletIndex]);
    return _isValidIndex ? new Bullet(*_bullet) : nullptr;
}


Consumable* Shop::SellConsumable()
{
	u_int _consumablesCount = 0;
	Consumable* _type = new Consumable(0, CT_MILK);
    string* _consumablesName = GetPurchasableItemsName(_type, _consumablesCount);

    const int _consumableIndex = OpenMenu(_consumablesName, _consumablesCount, "Que souhaitez-vous acheter comme consomable ?");
    delete[] _consumablesName;
    bool _isValidIndex = _consumableIndex >= 0 && _consumableIndex < _consumablesCount;

    Consumable* _consumable = dynamic_cast<Consumable*>(purchasableItems[_consumableIndex]);
    return _isValidIndex ? new Consumable(*_consumable) : nullptr;
}

string* Shop::GetPurchasableItemsName(PurchasableItem* _type, u_int& _arrayCount) const
{
	bool _isConsumable = dynamic_cast<Consumable*>(_type);
    string* _newArray = new string[purchasableItemsCount];

    for (u_int _i = 0; _i < purchasableItemsCount; _i++)
    {
        if ((_isConsumable && dynamic_cast<Consumable*>(purchasableItems[_i])) ||
            (!_isConsumable && dynamic_cast<Bullet*>(purchasableItems[_i])))
        {
            _newArray[_arrayCount++] = purchasableItems[_i]->GetTypeName();
        }
    }
    return _newArray;
}

void Shop::Close()
{
    player = nullptr;
}
