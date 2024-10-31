#pragma once
#include "WeaponWheel.h"
#include "Inventory.h"

class Entity
{
	string name;
	int life;
	Weapon* currentWeapon;
	WeaponWheel* wheel;
	Inventory* inventory;

public:
	WeaponWheel* GetWheel()const
	{
		return wheel;
	}

	Inventory* GetInventory()const
	{
		return inventory;
	}

public:
	Entity();
	~Entity();


public:
	virtual string ToString();

private:
	string RenderLife();
};

