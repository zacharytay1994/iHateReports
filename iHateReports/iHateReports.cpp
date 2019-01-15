// iHateReports.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "txtfile.h"
#include <string>
#include "trie.h"
#include "dictionary.h"

using namespace std;

int main()
{
	// Setting up txt to read
	Txtfile input("GutenPrepped.txt"); // Textfile to read from
	Txtfile output("output.txt"); // Textfile to have trimmed
	input.trimTxt(output);
	// Setting up guten dictionary
	Dictionary gutenDict(output, "guten");
	// Initiating dictionary
	gutenDict.initGutenberg();
	// Do stuff
	//gutenDict.displaySyn("polite");
	Txtfile paraphraseInput("paraphraseinput.txt");
	//cout << gutenDict.getRoot()->search("than") << endl;
	//gutenDict.getRoot()->searchClosest(gutenDict.getRoot(), "a");
	gutenDict.paraphrase(paraphraseInput);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
