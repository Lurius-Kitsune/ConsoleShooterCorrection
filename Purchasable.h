#pragma once
#include "UserInteract.h"
struct Purchasable
{
	virtual ~Purchasable() = default;
	virtual string ToString()const = 0;
};

