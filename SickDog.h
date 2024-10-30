#pragma once
#include "Dog.h"

class SickDog : public Dog
{
	string* weakness;

public:
	SickDog();
	SickDog(const string& _name, const int _pawsCount, const float _life,
		const double _barkPower, const string& _weakness);
	virtual ~SickDog();
public:
	virtual void Introduce() override;
	virtual void Bark() override;
	virtual void Sleep() override;
};

