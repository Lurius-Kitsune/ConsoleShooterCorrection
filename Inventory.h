#pragma once
#include "Consumable.h"
#include "Bullet.h"
class Inventory
{
	Consumable** consumables;
	u_int consumablesCount;
	Bullet** bullets;
	u_int bulletsCount;

public:
	Inventory();
	~Inventory();

public:

	//Inventory management
	void Open();

	// Consomable
	void OpenConsumable();
	string* GetConsumablesName() const;
	void AddConsumable(Consumable* _consumable);
	void RemoveConsumableByType(const ConsumableType* _type);

	// Bullet
	void OpenBullet();
	string* GetBulletsName() const;
	void AddBullet(Bullet* _consumable);
	void RemoveBulletByType(const BulletType& _type);
};

