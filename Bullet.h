#pragma once
#include "Macro.h"

enum BulletType
{
	BT_HOLLOW_POINT = 1,
	BT_BOAT_TAIL = 2,
	BT_ARROW = 3,
	BT_JACKETED_HOLLOW_POINT = 4,
	BT_ROUND_NOSE = 5,
	BT_PARTITION_BULLET = 6,
};

struct Bullet
{
	string name;
	BulletType type;


	int GetDamagesByType() const
	{
		return type;
	}
};

