#pragma once
#include "Consumable.h"
class Inventory
{
	Consumable** consumables;
	u_int consumablesCount;

public:
	Inventory();
	~Inventory();

public:
	void AddConsumable(Consumable* _consumable);
	void RemoveConsumable(const ConsumableType* _type);
	void RemoveConsumable(Consumable* _consumable);
};

