#include "Player.h"

Player::Player() 
{
	money = 0;
}

Player::Player(const string& _name, const int _life, WeaponWheel* _wheel)
	:Entity(_name, _life, _wheel)
{
	money = 0;
}
