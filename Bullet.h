#pragma once
#include "Macro.h"
#include "Purchasable.h"

struct Bullet : public Purchasable
{
	Bullet(const int _purchasePrice, const BulletType& _type);

	int GetDamages() const
	{
		return type;
	}

	string GetTypeName()const override;

	string ToString()const override;
};

