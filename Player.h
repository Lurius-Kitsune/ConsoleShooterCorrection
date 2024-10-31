#pragma once
#include "Entity.h"

class Player: public Entity
{
	u_int money;

public:
	Player();
	Player(const string& _name, const int _life,
		WeaponWheel* _wheel);
	~Player() = default;
};

