#pragma once
#include "Macro.h"
#include "PurchasableItem.h"
enum BulletType 
{
	BT_HOLLOW_POINT = 1,
	BT_BOAT_TAIL = 2,
	BT_ARROW = 3,
	BT_JACKETED_HOLLOW_POINT = 4,
	BT_ROUND_NOSE = 5,
	BT_PARTITION = 6,
};

struct Bullet : public PurchasableItem
{
	BulletType type;

	Bullet(const BulletType& _type);

	int GetDamagesByType() const
	{
		return type;
	}

	string GetTypeName()const override;

	string ToString()const override;
};

