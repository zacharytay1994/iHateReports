#include "pch.h"
#include "dictionary.h"

Dictionary::Dictionary(Txtfile dicttext, string formattype)
{
	dictText = dicttext;
	formatType = formattype;
}

bool Dictionary::initGutenberg(Trie*& trie)
{
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
				trie->insert(x, holder);
				
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
