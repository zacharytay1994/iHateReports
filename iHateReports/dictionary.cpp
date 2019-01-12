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
			if (checkKey)
			{
				x.erase(x.length() - 1, 1);
				trie->insert(x, holder);
				checkKey = false;
				//cout << x << endl;
				/*for (int r = 0; r < 50; r++)
				{
					tempArray[r] = "";
				}*/
				j = 0;
			}
			if (x == "ANT:")
			{
				checkSyn = false;
			}
			if (checkSyn)
			{
				holder->fillSynArray(holder, x, j);
				j++;
			}
			if (x == "KEY:")
			{
				checkKey = true;
			}
			if (x == "SYN:")
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
