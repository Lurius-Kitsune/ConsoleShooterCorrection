#pragma once
#include "Purchasable.h"
enum ConsumableType 
{
	CT_WATER,
	CT_MILK,
	CT_APPLE,
	CT_SPINACH
};

struct Consumable : public Purchasable
{
	int purchasePrice;
	ConsumableType type;

	int GetRegenValue() const
	{
		return type;
	}

	Consumable(const int _purcharsePrice, const ConsumableType& _type);

	string ToString()const override
	{
		return GetTypeName();
	}

	string GetTypeName()const;
private:
};

