#pragma once
#include <iostream>
#include <string>
using namespace std;

const int CHAR_SIZE = 128;
const int WORD_SIZE = 50;

// trie node
class Trie {
private:
public:
	bool isLeaf;
	Trie* character[CHAR_SIZE];
	string synonym[WORD_SIZE];
	Trie* holder;

	// Contructor
	Trie();
	// Insert new word in dictionary
	void insert(string, Trie*&);
	// Fills a word's synonym array
	void fillSynArray(Trie*, string, int);
	// Check is pointer has synonyms
	bool checkSyn();
	// Search from dictionary
	const bool search(const string);
	// Search Synonyms
	bool getWord(string, Trie*&);
	// Display all words from closest input
	const void searchClosest(Trie*, const string);
	// Find and display words from closest address
	void traverse(string, Trie*);
	// Search with insertion error check
	const bool searchErrorInsertion(string);
	// Search with deletion error check
	const bool searchErrorDeletion(string);
	// Search with substitution error check
	const bool searchErrorSubstitution(string);
	// Search with transposition error check
	const bool searchErrorTransposition(string);
};