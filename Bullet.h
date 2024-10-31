#pragma once
#include "Macro.h"
#include "PurchasableItem.h"

struct Bullet : public PurchasableItem
{
	BulletType type;

	Bullet(const int _purchasePrice, const BulletType& _type);

	int GetDamages() const
	{
		return type;
	}

	string GetTypeName()const override;

	string ToString()const override;
};

