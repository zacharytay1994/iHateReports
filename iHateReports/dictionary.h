#pragma once
#include <iostream>
#include <string>
#include "txtfile.h"
using namespace std;

class Dictionary {
private:
	Txtfile dictText;
public:
	Dictionary();
	Dictionary(Txtfile);
	void initGutenberg(); // To initiate a dictionary with the Gutenberg ebook format
};
