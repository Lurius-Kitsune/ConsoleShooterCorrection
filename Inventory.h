#pragma once
#include "Consumable.h"
#include "Bullet.h"
class Inventory
{
	Consumable** consumables;
	u_int consumablesCount;

public:
	Inventory();
	~Inventory();

public:
	// Consomable
	void AddConsumable(Consumable* _consumable);
	void RemoveConsumable(const ConsumableType* _type);

	// Bullet
	void AddBullet(Bullet* _consumable);
	void RemoveBullet(const BulletType* _type);
};

