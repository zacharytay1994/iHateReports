#pragma once
#include <iostream>
#include <string>

using namespace std;

class Word {
private:
	string word;
	string holderPunctuation = "";
public:
	Word(string);
	string getWord();
	void stripPunctuation();
	void packPunctuation(string&);
};
