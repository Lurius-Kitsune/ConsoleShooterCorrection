#pragma once
#include "Weapon.h"
#include "Consumable.h"
class Shop
{
	Weapon** weapons;
	u_int weaponsCount;
	Consumable** consumables;
	u_int consumablesCount;

public:
	Shop();
	~Shop();

public:
	void Open(Purchasable**& _purchasables, const u_int _purchasablesCount);

private:
	void DisplayWeapons()const;
	Weapon* SellWeapons();
	Weapon* GetWeaponByName(const string& _name) const;
	string* GetWeaponsName() const;
	void DisplayConsumable()const;
	string* GetConsumablesName() const;
	Consumable* SellConsumable();
};

