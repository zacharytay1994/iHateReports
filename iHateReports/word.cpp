#include "pch.h"
#include "word.h"

Word::Word(string _string)
{
	word = _string;
}

string Word::getWord()
{
	return word;
}

void Word::stripPunctuation()
{
	string holder = "";
	for (size_t i = 0; i < word.length(); i++)
	{
		if (word[i] >= 97 && word[i] <= 122)
		{
			holder += word[i];
		}
		else if (word[i] >= 65 && word[i] <= 90)
		{
			word[i] += 32;
			holder += word[i];
		}
		if (word[i] == 46 || word[i] == 44)
		{
			holderPunctuation += word[i];
		}
	}
	word = holder;
	//cout << holder << endl;
	//return string();
}

void Word::packPunctuation(string& _string)
{
	for (size_t i = 0; i < holderPunctuation.length(); i++)
	{
		if (holderPunctuation[i] == 44 || holderPunctuation[i] == 46)
		{
			_string += holderPunctuation[i];
		}
	}
}
