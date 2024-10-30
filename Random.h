#pragma once
#include <random>
#include <iostream>
#include <string>   
#include <conio.h>
#include <iomanip>
using namespace std;

typedef unsigned int u_int;

static int RandomInt(const u_int& _max, const u_int& _min)
{
    random_device _rSeed;
    mt19937 _gen(_rSeed());
    uniform_int_distribution<> distr(_min, _max);

    return distr(_gen);
}