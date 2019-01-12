#pragma once
#include <iostream>
#include <string>
#include "txtfile.h"
#include "trie.h"
using namespace std;

class Dictionary {
private:
	Txtfile dictText;
	string formatType; // FormatTypes: guten
	Trie* holder = nullptr;
public:
	//Dictionary();
	Dictionary(Txtfile, string);
	bool initGutenberg(Trie*&); // To initiate a dictionary with the Gutenberg ebook format
};
