#pragma once
#include "UserInteract.h"
enum BulletType
{
	BT_HOLLOW_POINT = 1,
	BT_BOAT_TAIL = 2,
	BT_ARROW = 3,
	BT_JACKETED_HOLLOW_POINT = 4,
	BT_ROUND_NOSE = 5,
	BT_PARTITION = 6,
};

enum ConsumableType
{
	CT_WATER,
	CT_MILK,
	CT_APPLE,
	CT_SPINACH
};

union AllPurchasableType
{
	BulletType bulletType;
	ConsumableType consumableType
};

enum PurchasableType
{
	PT_BULLET,
	PT_CONSUMABLE,

	PT_COUNT
};

// Todo Remove
struct PurchasableItem
{
	int purchasePrice;

	virtual int GetPurchasePrice() const
	{
		return purchasePrice;
	}

	PurchasableItem() = default;
	PurchasableItem(const int _purchasePrice);

	virtual ~PurchasableItem() = default;
	virtual string ToString()const = 0;
	virtual string GetTypeName()const = 0;
};

