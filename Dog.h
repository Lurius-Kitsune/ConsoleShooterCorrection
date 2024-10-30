#pragma once
#include "Animal.h"

class Dog : public Animal // Heritage fait !
{

protected:
	double* barkPower;

public:
	Dog();
	Dog(const string& _name, const float _life, const double _barkPower);

	virtual ~Dog();

public:
	virtual void Introduce() override;
	virtual void Eat() override;
	virtual void Sleep() override;
	virtual void Bark();
};

