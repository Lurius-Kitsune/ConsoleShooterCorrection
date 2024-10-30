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
