#pragma once
#include "Consumable.h"
#include "Bullet.h"

#define InventorySize GetPurchasablesSize(PurchasableType(PT_COUNT-1))

struct InventoryData
{
	string name;
	u_int count;

	InventoryData(const string& _name)
	{
		name = _name;
		count = 0;
	}

	InventoryData(const string& _name, const u_int& _count)
	{
		name = _name;
		count = _count;
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
		for (u_int _i = 0; _i < _categoryIndex+1; _i++)
		{
			_size += allData[_i].count;
		}
		return _size;
	}

public:

	u_int GetPurchasablesCountByType(const PurchasableType& _type)const
	{
		if (_type < 0 || _type >= PT_COUNT) return InventorySize;
		return allData[_type].count;
	}

	Inventory();
	Inventory(Purchasable** _purchasables, InventoryData* _inventoryData);
	~Inventory();

public:

	//Inventory management
	void Open();
	void OpenType(const PurchasableType& _categoryIndex);
	string* GetNamesOfType(const u_int& _indexToLook) const;
	void Add(const PurchasableType& _categoryIndex, Purchasable* _purchase);
	bool Remove(const PurchasableType& _purchaseType, const AllPurchasableType& _type);

	Purchasable* GetPurchasableByIndex(const PurchasableType _purchaseType, const u_int& _index) const;

	string* GetPurchasablesName(const PurchasableType _purchaseType) const;

private:
	u_int GetIndexByType(const PurchasableType& _purchaseType, const AllPurchasableType& _type) const;
	int GetTypeValue(const PurchasableType& _purchaseType, const AllPurchasableType& _type)const;
};

