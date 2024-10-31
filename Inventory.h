#pragma once
#include "Consumable.h"
#include "Bullet.h"

#define InventorySize GetPurchasablesSize(PT_COUNT)

struct InventoryData
{
	string name;
	u_int count;

	InventoryData(const string& _name)
	{
		name = _name;
		count = 0;
	}
};

class Inventory
{
	Purchasable** purchasables;
	InventoryData* allData;

private:
	u_int GetPurchasablesSize(const PurchasableType& _categoryIndex)const
	{
		u_int _size = 0;
		for (u_int _i = 0; _i < _categoryIndex; _i++)
		{
			_size += allData[_i].count;
		}
		return _size;
	}
public:
	Inventory();
	~Inventory();

public:

	//Inventory management
	void Open();
	void OpenType(const PurchasableType& _categoryIndex);
	string* GetNamesOfType(const u_int& _indexToLook) const;
	void Add(const PurchasableType& _categoryIndex, Purchasable* _purchase);
	bool Remove(const PurchasableType& _purchaseType, const AllPurchasableType& _type);


private:
	u_int GetIndexByType(const PurchasableType& _purchaseType, const AllPurchasableType& _type) const;
};

