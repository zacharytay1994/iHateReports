#include "pch.h"
#include "dictionary.h"

Dictionary::Dictionary(Txtfile dicttext, string formattype)
{
	dictText = dicttext;
	formatType = formattype;
}

Trie* Dictionary::getRoot()
{
	if (root != nullptr)
	{
		return root;
	}
	else
	{
		cout << "Dictionary not initialized" << endl;
	}
}

bool Dictionary::initGutenberg()
{
	root = new Trie;
	bool checkKey = false;
	bool checkSyn = false;
	if (formatType == "guten")
	{
		ifstream gutenFile;
		gutenFile.open(dictText.getFileName());
		string x;
		//string tempArray[50];
		int j = 0;
		while (gutenFile >> x)
		{
			if (x == ".")
			{
				checkSyn = false;
				checkKey = false;
			}
			if (checkKey)
			{
				//x.erase(x.length() - 1, 1);
				root->insert(x, holder);
				
				//cout << x << endl;
				/*for (int r = 0; r < 50; r++)
				{
					tempArray[r] = "";
				}*/
				j = 0;
			}
			if (checkSyn)
			{
				holder->fillSynArray(holder, x, j);
				j++;
			}
			if (x == "keyC")
			{
				checkKey = true;
			}
			if (x == "synC")
			{
				checkSyn = true;
			}
		}
		return true;
		gutenFile.close();
		
	}
	else
	{
		return false;
	}
}

void Dictionary::displaySyn(string _string)
{
	if (root != nullptr)
	{
		Trie* wordLoc = new Trie;
		if (root->getWord(_string, wordLoc))
		{
			for (int z = 0; z < 50; z++)
			{
				if (!(wordLoc->synonym[z] == ""))
				{
					cout << wordLoc->synonym[z] << endl;
				}
			}
		}
	}
	else
	{
		cout << "Dictionary not initialized, initGutenberg()." << endl;
	}
}
