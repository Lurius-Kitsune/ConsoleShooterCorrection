#pragma once
#include "UserInteract.h"

// Todo Remove
struct Purchasable
{
	virtual ~Purchasable() = default;
	virtual string ToString()const = 0;
};

