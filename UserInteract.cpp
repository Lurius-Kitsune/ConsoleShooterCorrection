#include "UserInteract.h"

int GetInt()
{
	int _answer;
	bool _isValid;

	DISPLAY("Réponse : ", false);
	do
	{
		cin >> _answer;
		_isValid = cin.good();
		CLEAR;
	} while (!_isValid);
	
	return _answer;
}

string GetLine(const string& _question)
{
	DISPLAY(_question, _question.empty() ? false : true)
	string _line = string();
	bool _wantToQuit;

	do
	{
		const int _charASCII = getchar();
		_wantToQuit = _charASCII == EOF || _charASCII == '\n';

		if (!_wantToQuit)
		{
			_line += char(_charASCII);
		}

	} while (!_wantToQuit);

	return _line;
}

bool GetBool(const string& _answersPossible)
{
	DISPLAY(_answersPossible, true);
	DISPLAY("Réponse : ", false);
	bool _answer;
	cin >> _answer;
	CLEAR;
	return _answer;
}

void DisplayMenu(const string* _options, const int _currentIndex, const u_int& _maxOptions, const string& _question)
{
	DISPLAY(_question, _question.empty() ? false : true);
	DISPLAY("==========ACTION==========", true);
	for (u_int _i = 0; _i <= _maxOptions; _i++)
	{
		string _firstSymbol = "", _secondSymbol = "" RESET;
		if (_i == _currentIndex)
		{
			_firstSymbol = YELLOW "[";
			_secondSymbol = YELLOW "]" RESET;
		}
		DISPLAY(_firstSymbol + (_i == _maxOptions ? "Quitter" : _options[_i]) + _secondSymbol, true);
	}
	DISPLAY("==========================", true);
}

int OpenMenu(const string* _options, const u_int& _maxOptions, const string& _question)
{
	int _currentIndex = 0;
	DisplayMenu(_options, _currentIndex, _maxOptions, _question);
	do
	{
		
		if (_kbhit())
		{
			// Attendre une touche
			u_int _input = 0;
			_input = _getch();

			// Si la touche est entrée, alors _isChoiceMade = true
			switch (_input)
			{
			case 13:
				return _currentIndex;
				// Si la touche est fleche du haut, alors _choiceIndex--
			case 72:
				_currentIndex--;
				// Si _choiceIndex < 0, alors _choiceIndex = _maxChoice-1 (car tableau)
				if (_currentIndex < 0)
				{
					_currentIndex = _maxOptions - 1;
				}
				break;
				// Si la touche est fleche du bas, alors _choiceIndex++
			case 80:
				_currentIndex++;
				if (_currentIndex > _maxOptions)
				{
					_currentIndex = 0; // on retourne en haut
				}
				break;
			default:
				break;
			}
			CLEAR_SCREEN;
			DisplayMenu(_options, _currentIndex, _maxOptions, _question);
		}
		
	} while (true);
}

