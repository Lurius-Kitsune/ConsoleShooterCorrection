#pragma once
#include "Macro.h"
class Weapon
{
	string name;
	string description;
	int buyingPrice;
	string skin; // color
	float accuracy;

public:
	//Weapon() = default;
	Weapon(const string& _name, const string& _description, const int _buyingPrice,
		const string& _skin, const float _accuracy);

public: 
	virtual void Attack() = 0;
	virtual string ToString();
	virtual void Drop();
};

