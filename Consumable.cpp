#include "Consumable.h"

Consumable::Consumable(const int _purcharsePrice, const ConsumableType& _type)
{
	purchasePrice = _purcharsePrice;
	type = _type;
}

string Consumable::GetTypeName()const
{
	switch (type)
	{
	case CT_WATER:
		return "Water";
	case CT_MILK:
		return "Le bon lait de Marguerite";
	case CT_APPLE:
		return "Pomme";
	case CT_SPINACH:
		return "Epinard";
	default:
		return "None";
	}
}
