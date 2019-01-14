#pragma once
#include <iostream>
#include <string>
#include "txtfile.h"
#include "trie.h"
#include <fstream>
#include <random>
#include "word.h"

using namespace std;

class Dictionary {
private:
	Txtfile dictText;
	string formatType; // FormatTypes: guten
	Trie* holder = nullptr;
	Trie* root = nullptr;
public:
	//Dictionary();
	Dictionary(Txtfile, string);
	// Return root
	Trie* getRoot();
	// pushing words from dictionary into trie data structure
	bool initGutenberg(); // To initiate a dictionary with the Gutenberg ebook format
	// Print out synonyms
	void displaySyn(string);
	// Returns a random synonym
	bool returnSyn(string&);
	// Paraphrase text file
	void paraphrase(Txtfile);
};
