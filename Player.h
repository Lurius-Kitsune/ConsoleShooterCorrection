#pragma once
#include "WeaponWheel.h"
#include "Inventory.h"

class Player
{
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
	Player();
	~Player();
};

