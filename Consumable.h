#pragma once
#include "Purchasable.h"

struct Consumable : public Purchasable
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

