#include "pch.h"
#include "dictionary.h"

Dictionary::Dictionary(Txtfile dicttext, string formattype)
{
	dictText = dicttext;
	formatType = formattype;
}

bool Dictionary::initGutenberg(Trie*& trie)
{
	bool check = false;
	if (formatType == "guten")
	{
		ifstream gutenFile;
		gutenFile.open(dictText.getFileName());
		string x;
		while (gutenFile >> x)
		{
			if (check)
			{
				x.erase(x.length() - 1, 1);
				trie->insert(x);
				check = false;
				//cout << x << endl;
			}
			if (x == "KEY:")
			{
				check = true;
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
