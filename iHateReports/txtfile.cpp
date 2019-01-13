#include "pch.h"
#include "txtfile.h"
#include <ctype.h>

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

void Txtfile::trimTxt(Txtfile output) // Make sure file has all braces converted to A, and quotations converted to B
{
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(fileName);
	outputFile.open(output.fileName);
	string x;
	bool read = true;
	while (getline(inputFile, x) && x != "")
	{
		string holder = "";
		for (size_t i = 0; i < x.length(); i++)
		{
			// Check for A
			if (x[i] == 65)
			{
				if (read)
				{
					read = false;
				}
				else
				{
					read = true;
				}
			}
			// Check for O and P
			if (x[i] == 79)
			{
				read = false;
			}
			else if (x[i] == 80)
			{
				read = true;
			}
			if (read && x[i] != 65 && x[i] != 80)
			{
				if (x[i] == 66)
				{
					holder += "-";
				}
				else
				{
					holder += x[i];
				}
			}
		}
		outputFile << holder << endl;
	}
	inputFile.close();
	outputFile.close();
}
