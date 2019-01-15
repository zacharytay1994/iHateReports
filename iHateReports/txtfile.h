#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Txtfile {
private:
	string fileName;
public:
	Txtfile();
	Txtfile(string);
	const string getFileName();
	const void writeToFile(string);
	const string readFile();
	void trimTxt(Txtfile); // trim a text Document to remove non-alphabetical characters
};