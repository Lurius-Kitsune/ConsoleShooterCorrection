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
void Shop::Open(Purchasable**& _purchasables, const u_int _purchasablesCount)
{

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
    string* _weaponsName = GetConsumablesName();
    const int _weaponsIndex = OpenMenu(_weaponsName, weaponsCount);
    delete[] _weaponsName;
    return weapons[_weaponsIndex];
}

Weapon* Shop::GetWeaponByName(const string& _name) const
{
    for (u_int _i = 0; _i < weaponsCount; _i++)
    {
        if (weapons[_i]->GetName() == _name)
        {
            return weapons[_i];
        };
    }
    return nullptr;
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
    return consumables[_consumableIndex];
}
