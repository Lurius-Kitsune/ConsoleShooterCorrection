#pragma once
#include "UserInteract.h"

// Todo Remove
struct PurchasableItem
{
	virtual ~PurchasableItem() = default;
	virtual string ToString()const = 0;
	virtual string GetTypeName()const = 0;
};

