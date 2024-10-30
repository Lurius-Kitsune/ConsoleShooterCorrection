#pragma once
#include "WeaponWheel.h"

class Player
{
	WeaponWheel* wheel;

public:
	WeaponWheel* GetWheel()const
	{
		return wheel;
	}

public:
	Player();
	~Player();
};

