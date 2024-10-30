#pragma once
#include "Macro.h"     

using namespace std;

typedef unsigned int u_int;

int GetInt();
string GetLine(const string& _question = "");

bool GetBool(const string& _answersPossible = "[0] Oui\t[1] Non");

void DisplayMenu(const string* _options, const int _currentIndex, const u_int& _maxOptions, const string& _question);
int OpenMenu(const string* _options, const u_int& _maxOptions, const string& _question = "");

