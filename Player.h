#pragma once
#include "Entity.h"

class Player: public Entity
{
	u_int money;

public:
	Player();
	~Player() = default;
};

