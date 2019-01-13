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

void Txtfile::trimTxt(Txtfile output)
{
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(fileName);
	outputFile.open(output.fileName);
	string x;
	while (getline(inputFile, x) && x != "")
	{
		string holder = "";
		for (size_t i = 0; i < x.length(); i++)
		{
			if (((x[i] + 32) >= 97 && x[i] <= 122))
			{
				if (x[i] >= 97)
				{
					holder += x[i];
				}	
			}
			else
			{
				holder += " ";
			}
		}
		outputFile << holder << endl;
	}
	inputFile.close();
	outputFile.close();
	string test = "brack[\]\{\(}/";
	cout << test << endl;
}
