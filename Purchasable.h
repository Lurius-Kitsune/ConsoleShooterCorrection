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
	ConsumableType consumableType;

	AllPurchasableType()
	{
		bulletType = BulletType();
		consumableType = ConsumableType();
	}

	AllPurchasableType(BulletType _bulletType)
	{
		bulletType = _bulletType;
	}
	AllPurchasableType(ConsumableType _consumableType)
	{
		consumableType = _consumableType;
	}
};

enum PurchasableType
{
	PT_BULLET,
	PT_CONSUMABLE,

	PT_COUNT
};

// Todo Remove
struct Purchasable
{
	int purchasePrice;
	PurchasableType type;
	AllPurchasableType allTypes;

	virtual int GetPurchasePrice() const
	{
		return purchasePrice;
	}

	Purchasable() = default;
	Purchasable(const int _purchasePrice, const PurchasableType& _type, const AllPurchasableType& _allTypes);

	virtual ~Purchasable() = default;
	u_int GetType()const;
	virtual string ToString()const = 0;
	virtual string GetTypeName()const = 0;
};

