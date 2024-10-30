#pragma once
#include "Player.h"
class Shop
{
	Weapon** weapons;
	u_int weaponsCount;
	PurchasableItem** purchasableItems;
	u_int purchasableItemsCount;
	Player* player;

public:
	Shop();
	~Shop();

public:
	void Open(Player* _player);

private:
	// Weapon
	Weapon* SellWeapons();
	string* GetWeaponsName() const;

	//Bullet
	Bullet* SellBullets();

	//Consumable
	Consumable* SellConsumable();

	//PurchsableItem
	string* GetPurchasableItemsName(PurchasableItem* _type, u_int& _arrayCoun) const;

	void Close();
};

