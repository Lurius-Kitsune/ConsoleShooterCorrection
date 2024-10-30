#pragma once
#include "Weapon.h"
#include "Consumable.h"
#include "Player.h"
class Shop
{
	Weapon** weapons;
	u_int weaponsCount;
	Consumable** consumables;
	u_int consumablesCount;
	Player* player;

public:
	Shop();
	~Shop();

public:
	void Open(Player* _player);

private:
	// Weapon
	Weapon* SellWeapons();
	string* GetWeaponsName() const;

	//Consumable
	string* GetConsumablesName() const;
	Consumable* SellConsumable();

	void Close();
};

