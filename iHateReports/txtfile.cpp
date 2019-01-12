#include "pch.h"
#include "txtfile.h"

Txtfile::Txtfile()
{
}

Txtfile::Txtfile(string filename)
{
	fileName = filename;
}

const string Txtfile::getFileName()
{
	return fileName;
}

const void Txtfile::writeToFile(string text)
{
	ofstream writeFile;
	writeFile.open(fileName);
	writeFile << text;
	writeFile.close();
}

const string Txtfile::readFile()
{
	ifstream readFile;
	readFile.open(fileName);
	string x;
	string returnString = "";
	while (readFile >> x)
	{
		returnString += x + " ";
	}
	return returnString;
}