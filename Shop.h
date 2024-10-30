#pragma once
#include "Player.h"
class Shop
{
	Weapon** weapons;
	u_int weaponsCount;
	Consumable** consumables;
	u_int consumablesCount;
	Bullet** bullets;
	u_int bulletsCount;
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

	//Bullet
	string* GetBulletName() const;
	Bullet* SellBullet();

	//Consumable
	string* GetConsumablesName() const;
	Consumable* SellConsumable();

	void Close();
};

