#include "Consumable.h"

Consumable::Consumable(const int _purcharsePrice, const ConsumableType& _type)
	: Purchasable(_purcharsePrice, PT_CONSUMABLE, AllPurchasableType(_type)) 
{
	type = _type;
}

string Consumable::GetTypeName()const
{
	switch (type)
	{
	case CT_WATER:
		return "Water";
	case CT_MILK:
		return "MILK";
	case CT_APPLE:
		return "Pomme";
	case CT_SPINACH:
		return "Epinard";
	default:
		return "None";
	}
}
