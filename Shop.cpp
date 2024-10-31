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

    inventory = new Inventory(new Purchasable * [10]
    {
        new Bullet(0, BT_PARTITION),
        new Bullet(0, BT_ARROW),
        new Bullet(0, BT_BOAT_TAIL),
        new Bullet(0, BT_HOLLOW_POINT),
        new Bullet(0, BT_JACKETED_HOLLOW_POINT),
        new Bullet(0, BT_ROUND_NOSE),
        new Consumable(0, CT_MILK),
        new Consumable(0, CT_APPLE),
        new Consumable(0, CT_SPINACH),
        new Consumable(0, CT_WATER)
    },
    new InventoryData[2]
    {
        InventoryData("Munition", 6),
        InventoryData("Consomable", 4)
    }
    );
}

Shop::~Shop()
{
    for (u_int _i = 0;  _i < weaponsCount;  _i++)
    {
        delete weapons[_i];
    }
    delete[] weapons;
    delete inventory;
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
            if (Consumable* _purchase = dynamic_cast<Consumable*>(Sell(PT_CONSUMABLE)))
            {
                _purchase = new Consumable(*_purchase);
                player->GetInventory()->Add(PT_CONSUMABLE, _purchase);
            }
        }
        else if (_menuIndex == 2)
        {
            if (Bullet* _purchase = dynamic_cast<Bullet*>(Sell(PT_BULLET)))
            {
                _purchase = new Bullet(*_purchase);
                player->GetInventory()->Add(PT_BULLET, _purchase);
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

Purchasable* Shop::Sell(const PurchasableType& _purchaseType)
{
    string* _purchasesName = inventory->GetPurchasablesName(_purchaseType);

    const u_int& _purchaseIndex = OpenMenu(_purchasesName, inventory->GetPurchasablesCountByType(_purchaseType), "Quelle item souhaitez-vous acheter ?");
    delete[] _purchasesName;

    return inventory->GetPurchasableByIndex(_purchaseType ,_purchaseIndex);
}

void Shop::Close()
{
    player = nullptr;
}
