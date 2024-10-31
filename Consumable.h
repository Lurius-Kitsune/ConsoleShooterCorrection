#pragma once
#include "PurchasableItem.h"

struct Consumable : public PurchasableItem
{
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

	string GetTypeName()const override;
private:
};

