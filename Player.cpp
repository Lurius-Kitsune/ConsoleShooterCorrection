#include "Player.h"

Player::Player()
{
	wheel = new WeaponWheel();
	inventory = new Inventory();
}

Player::~Player()
{
	delete wheel;
	delete inventory;
}
