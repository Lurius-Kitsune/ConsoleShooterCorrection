#pragma once
#include "Macro.h"

class Animal // classe abstraite
{
	string* name;

protected:
	int pawsCount;
	float life;

public: 
	string* GetName() const
	{
		return name;
	}

public:
	Animal();
	Animal(const string& _name, const int _pawsCount, const float _life);
	virtual ~Animal();

protected:
	virtual void Introduce();
public:
	virtual void Eat() = 0; // Virtual signifie que la fonction existe sur les classe fille !
	virtual void Sleep() = 0;
};

