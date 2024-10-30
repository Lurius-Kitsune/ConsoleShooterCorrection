#pragma once
#include "Soldier.h"
class GameWar
{
	Soldier* player;
	Soldier* ennemy;

public:
	GameWar() = default;

	GameWar(const string& _name, const int _life, Weapon* _currentWeapon);
	GameWar(const string& _name, const int _life, Weapon* _currentWeapon,
		Weapon** _weapons, const u_int& _weaponsSize);
	~GameWar();
public: 
	void LaunchGame();
private:
	void DisplayGameStatus();

	u_int SelectPlayerAction();
	void PlayerChoice(const string* _choices, int& _choiceIndex, const u_int& _maxChoice);
	void SpawnEnnemy();

	void DoAction(const u_int& _choice, Soldier*& _soldierTurn, Soldier*& _target);
};

