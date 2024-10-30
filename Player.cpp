#include "Player.h"

Player::Player()
{
	wheel = new WeaponWheel();
}

Player::~Player()
{
	delete wheel;
}
