// File Main.h
#pragma once
#include "ConsolMacroColor.h"

//using namespace std;
//
//typedef unsigned int u_int;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define CLEAR cin.clear(); \
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

#define DISPLAY(_value, _makeEndl) cout << _value; \
                                   if (_makeEndl) cout << endl;
#define SPACE DISPLAY("", true);
#define DISPLAY_LINE DISPLAY("=========================", true);

#define CLEAR_SCREEN system("cls");

#pragma region Forward
// Forward
void Config();
#pragma endregion

