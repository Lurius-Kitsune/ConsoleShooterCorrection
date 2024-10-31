#include "Purchasable.h"

Purchasable::Purchasable(const int _purchasePrice, const PurchasableType& _type, const AllPurchasableType& _allTypes)
{
	purchasePrice = _purchasePrice;
	type = _type;
	allTypes = _allTypes;
}

u_int Purchasable::GetType() const
{
	switch (type)
	{
	case PT_BULLET:
		return allTypes.bulletType;
	case PT_CONSUMABLE:
		return allTypes.consumableType;
	default:
		return 0;
	}
}
