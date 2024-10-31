#include "Inventory.h"

Inventory::Inventory()
{
	allData = new InventoryData[2]
	{
		InventoryData("Consomable"),
		InventoryData("Munition"),
	};
	purchasables = new Purchasable * [0];
}

Inventory::Inventory(Purchasable** _purchasables, InventoryData* _inventoryData)
{
	purchasables = _purchasables;
	allData = _inventoryData;
}

Inventory::~Inventory()
{
	const u_int& _purchasablesSize = InventorySize;
	for (u_int _i = 0; _i < _purchasablesSize; _i++)
	{
		delete purchasables[_i];
	}
	delete[] purchasables;

	delete[] allData;
}

void Inventory::Open()
{
	const string _inventoryCategoriesNames[] =
	{
		"Munition",
		"Consomable"
	};

	const u_int& _inventoryCategoriesCount = size(_inventoryCategoriesNames);
	int _menuIndex;
	do
	{
		_menuIndex = OpenMenu(_inventoryCategoriesNames, _inventoryCategoriesCount, "Quel magasin accéder ?");
		CLEAR_SCREEN;
		if (_menuIndex >= 0 && _menuIndex < PT_COUNT)
		{
			OpenType(PurchasableType(_menuIndex));
		}
		else
		{
			break;
		}
	} while (true);

}

void Inventory::OpenType(const PurchasableType& _category)
{
	const u_int _sizeOfCategory = GetPurchasablesCountByType(_category);
	if(_sizeOfCategory > 0)
	{
		const u_int& _indexToLook = _category - 1 < 0 ? 0 : GetPurchasablesSize(PurchasableType(_category - 1));
		
		string* _namesOfType = GetPurchasablesName(_category);
		const u_int& _consumablesIndex = OpenMenu(_namesOfType, _sizeOfCategory, "Quel type souhaite-tu voir ?");
		delete[] _namesOfType;
		// Todo Upgrade it!
		do
		{
			if (_consumablesIndex < _indexToLook)
			{
				DISPLAY("Using consumable: " , true);
				//Remove(&_consumable->type);
			}
			else
			{
				break;
			}
		} while (true);
	}
	else
	{
		string _noneOf = _category == 0 ? "aucune munitions" : "aucun consomable";
		DISPLAY(RED "[INFO] Tu ne possède " + _noneOf + RESET, true);
	}
}

void Inventory::Add(const PurchasableType& _category, Purchasable* _purchase)
{
	const u_int& _inventorySize = InventorySize == 0 ? 1 : InventorySize;
	Purchasable** _tempPurchasable = new Purchasable *[_inventorySize + 1];
	const u_int& _indexToAdd = GetPurchasablesSize(_category);
	bool _hasSet = false;

	for (u_int _i = 0; _i < _inventorySize; _i++)
	{
		if (_i == _indexToAdd)
		{
			_tempPurchasable[_i] = _purchase;
			_hasSet = true;
		}
		_tempPurchasable[_i + _hasSet] = purchasables[_i];
	}

	delete purchasables;
	purchasables = _tempPurchasable;
	allData[_category].count++;
}

bool Inventory::Remove(const PurchasableType& _purchaseType, const AllPurchasableType& _type)
{
	const u_int& _inventorySize = InventorySize;
	const u_int& _indexToRemove = GetIndexByType(_purchaseType, _type);

	if (_indexToRemove == _inventorySize) return false;

	Purchasable** _tempPurchasable = new Purchasable * [_inventorySize - 1];
	bool _hasSkip = false;
	Purchasable* _purchase = nullptr;
	for (u_int _i = 0; _i < _inventorySize; _i++)
	{
		if (!_hasSkip && _i == _indexToRemove)
		{
			_hasSkip = true;
			_purchase = purchasables[_i];
			continue;
		}
		_tempPurchasable[_i] = purchasables[_i + _hasSkip];
	}
	delete _purchase;
	delete purchasables;
	purchasables = _tempPurchasable;
	return true;
}

Purchasable* Inventory::GetPurchasableByIndex(const PurchasableType _purchaseType, const u_int& _index) const
{
	const u_int& _typeCount = GetPurchasablesCountByType(_purchaseType);
	const u_int& _startIndex = _purchaseType - 1 < 0 ? 0 : GetPurchasablesSize(PurchasableType(_purchaseType - 1));
	if (_index < 0 || _index >= _typeCount) return nullptr;

	return purchasables[_startIndex + _index];
}

 string* Inventory::GetPurchasablesName(const PurchasableType _purchaseType) const
{
	 const u_int& _startIndex = _purchaseType - 1 < 0 ? 0 : GetPurchasablesSize(PurchasableType(_purchaseType - 1));
	 const u_int& _stopIndex = GetPurchasablesSize(_purchaseType);
	 const int _typeValue = _purchaseType;
	 const u_int& _arraysize = _stopIndex - _startIndex;
	 string* _newArray = new string[_arraysize];
	 for (u_int _i = 0; _i < _arraysize; _i++)
	 {
		 _newArray[_i] = purchasables[_startIndex+_i]->ToString();
	 }
	 return _newArray;
}

u_int Inventory::GetIndexByType(const PurchasableType& _purchaseType, const AllPurchasableType& _allType) const
{
	const u_int& _startIndex = _purchaseType - 1 < 0 ? 0 : GetPurchasablesSize(PurchasableType(_purchaseType-1));
	const u_int& _stopIndex = GetPurchasablesSize(_purchaseType);
	const int _typeValue = GetTypeValue(_purchaseType, _allType);
	for (u_int _i = _startIndex; _i < _stopIndex; _i++)
	{
		if (purchasables[_i]->GetType() == _typeValue)
		{
			return _i;
		}
	}
	return -1;
}

int Inventory::GetTypeValue(const PurchasableType& _purchaseType, const AllPurchasableType& _allType) const
{
	if (_purchaseType == PT_BULLET)
	{
		return _allType.bulletType;
	}
	else if (_purchaseType == PT_CONSUMABLE)
	{
		return _allType.consumableType;
	}
	return -1;
}
