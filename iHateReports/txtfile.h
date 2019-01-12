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
	void writeToFile(string);
	string readFile();
};