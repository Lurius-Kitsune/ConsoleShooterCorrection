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
	void Open(Purchasable**& _purchasables, u_int& _purchasablesCount);

private:
	void DisplayWeapons()const;
	Weapon* SellWeapons();
	string* GetWeaponsName() const;
	void DisplayConsumable()const;
	string* GetConsumablesName() const;
	Consumable* SellConsumable();
	void AddPurchasable(Purchasable**& _purchasables, u_int& _purchasablesCount, Purchasable* _purchase);
};

