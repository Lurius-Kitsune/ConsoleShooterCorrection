#include "Shop.h"
#include "WeaponMelee.h"
#include "WeaponRange.h"
Shop::Shop()
{
    weapons = new Weapon * [1]
        {
            new WeaponRange("AK-47", "Pan-Pan", BLINK_TEXT  RED, 1000, 12.2f, 10, BT_PARTITION_BULLET),
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
}

/// <summary>
/// Ouvre un magasin
/// </summary>
/// <param name="_purchasables">Purchasable qui vont etre affecter</param>
/// <param name="_purchasablesCount">Le nb d'objet</param>
void Shop::Open(Purchasable**& _purchasables, u_int& _purchasablesCount)
{
    const string _shopItemNames[] =
    {
        "Armes",
        "Consomable"
    };
    const u_int& _shopItemNamesCount = size(_shopItemNames);
    int _menuIndex;
    do
    {
        _menuIndex = OpenMenu(_shopItemNames, _shopItemNamesCount);
        Purchasable* _purchase;
        if (_menuIndex == 0)
        {
            _purchase = SellWeapons();
            AddPurchasable(_purchasables, _purchasablesCount, _purchase);
        }
        else if (_menuIndex == 1)
        {
            _purchase = SellConsumable();
            AddPurchasable(_purchasables, _purchasablesCount, _purchase);
        }
        else
        {
            break;
        }
    } while (true);
    

}

void Shop::DisplayWeapons() const
{
    for (u_int _i = 0; _i < weaponsCount; _i++)
    {
        DISPLAY(weapons[_i]->ToString(), true);
    }
}

Weapon* Shop::SellWeapons()
{
    DISPLAY("Que souhaitez-vous acheter comme arme ?", true);
    string* _weaponsName = GetWeaponsName();
    const int _weaponsIndex = OpenMenu(_weaponsName, weaponsCount);
    delete[] _weaponsName;
    bool _isValidIndex = _weaponsIndex >= 0 && _weaponsIndex < weaponsCount;
    Weapon* _weapon = weapons[_weaponsIndex];
    return _isValidIndex ? new Weapon(*_weapon) : nullptr;
}

string* Shop::GetWeaponsName() const
{
    string* _newArray = new string[weaponsCount];
    for (u_int _i = 0; _i < weaponsCount; _i++)
    {
        _newArray[_i] = weapons[_i]->GetName();
    }
    return _newArray;
}

void Shop::DisplayConsumable() const
{
    for (u_int _i = 0; _i < consumablesCount; _i++)
    {
        DISPLAY(consumables[_i]->ToString(), true);
    }
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
    DISPLAY("Que souhaitez-vous acheter comme consomable ?", true);
    string* _consumablesName = GetConsumablesName();
    const int _consumableIndex = OpenMenu(_consumablesName, consumablesCount);
    delete[] _consumablesName;
    bool _isValidIndex = _consumableIndex >= 0 && _consumableIndex < consumablesCount;
    Consumable* _consumable = consumables[_consumableIndex];
    return _isValidIndex ? new Consumable(*_consumable) : nullptr;
}

void Shop::AddPurchasable(Purchasable**& _purchasables, u_int& _purchasablesCount, Purchasable* _purchase)
{
    if (!_purchase) return;

    Purchasable** _tempPurchasable = new Purchasable * [_purchasablesCount + 1];
    for (u_int _i = 0; _i < _purchasablesCount; _i++)
    {
        _tempPurchasable[_i] = _purchasables[_i];
    }

    _tempPurchasable[_purchasablesCount] = _purchase;
    delete _purchasables;
    _purchasables = _tempPurchasable;
    _purchasablesCount++;
}
