#include "pch.h"
#include "trie.h"

Trie::Trie()
{
	this->isLeaf = false; // this = address of object, sets to root

	// Initializes character addresses to null
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		this->character[i] = nullptr; // nullptr is the same as NULL but newer
	}
}

void Trie::insert(string key, Trie*& trie)
{
	// Create pointer pointing to address of root node (this)
	Trie* current = this;
	int temp; // Temp is used to convert capital letters to small letters when needed.
	for (size_t i = 0; i < key.length(); i++)
	{
		// Create node if path not found
		if (key[i] < 97)
		{
			temp = key[i] + 32; // Converts capital letters to small letters
		}
		else
		{
			temp = key[i];
		}
		if (current->character[temp] == nullptr) // Checks if address of index Letter is null
		{
			current->character[temp] = new Trie(); // Sets index Letter of character array to new trie
		}
		
		current = current->character[temp]; // Traverse from root to existing or newly created trie address
	}
	// Mark current node as leaf
	trie = current;
	current->isLeaf = true;
}

void Trie::fillSynArray(Trie* trie, string _word, int i)
{
	trie->synonym[i] = _word;
}

const bool Trie::search(const string key)
{
	// If object trie is empty
	if (this == nullptr)
	{
		return false;
	}

	Trie* current = this; // Get root address
	for (size_t i = 0; i < key.length(); i++)
	{
		// traverse to next node
		current = current->character[key[i]];

		if (current == nullptr) // If next node is null, meaning word not registered
		{
			return false;
		}
	}
	return current->isLeaf; // If entire word is found, last letter->isLeaf would return true
}

bool Trie::getWord(string _string, Trie*& trie)
{
	Trie* current = this;
	if (!current->search(_string))
	{
		cout << "Word does not exist in dictionary." << endl;
		return false;
	}
	else
	{
		for (size_t i = 0; i < _string.length(); i++)
		{
			current = current->character[_string[i]];
		}
		if (current->isLeaf)
		{
			trie = current;
			return true;
		}
	}
}

const void Trie::searchClosest(Trie* trie, string prefix)
{
	bool check = true;
	if (trie->search(prefix)) // If prefix is a word
	{
		cout << prefix << endl;
	}
	// If trie is empty
	if (this == nullptr)
	{
		cout << "There is nothing in this damn text file." << endl;
	}
	else
	{
		Trie* current = this;
		for (size_t i = 0; i < prefix.length(); i++)
		{
			if (current->character[prefix[i]] == nullptr)
			{
				cout << "No such word with prefix found." << endl; // If no prefix exist, break and exit function
				check = false;
				break;
			}
			else
			{
				current = current->character[prefix[i]]; // Traverse pointer to latest character
			}
		}
		if (check) // If prefix check is true
		{
			traverse(prefix, current); // Call traverse display script
		}
	}
}

void Trie::traverse(string prefix, Trie* trie)
{
	for (size_t i = 0; i < CHAR_SIZE; i++)
	{
		if (trie->character[i] != nullptr) // Check if array index is null
		{
			Trie* temp = trie->character[i]; // Get pointer to check through array
			char asciiChar = char(i); // Convert int index to ascii character
			string tempString = prefix + asciiChar; // Join character to prefix
			if (!temp->isLeaf)
			{
				traverse(tempString, temp); // If not leaf, recurse with new prefix and address
			}
			else
			{
				cout << "Word Found: " + tempString << endl;	// Else print out word
				cout << "---- Synonym ----" << endl;
				for (int z = 0; z < 50; z++)
				{
					if (!(temp->synonym[z] == ""))
					{
						cout << temp->synonym[z] << endl;
					}	
				}
			}
		}
	}
}

const bool Trie::searchErrorInsertion(string key)
{
	bool check = false;
	Trie* current = this;
	if (current->search(key))
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < key.length(); i++)
		{
			string holder = key;
			holder.erase(i, 1);
			if (current->search(holder))
			{
				cout << "Insertion error detected." << endl;
				cout << "Did you mean: " + holder + "?" << endl;
				check = true;
			}
		}
		if (!check)
		{
			cout << "Sorry bro, your word does not exist or your spelling sucks." << endl;
			return false;
		}
		return true;
	}
}

const bool Trie::searchErrorDeletion(string key)
{
	char cArray[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; // I know its probably not the best way
	bool check = false;
	Trie* current = this;
	if (current->search(key))
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < key.length(); i++)
		{
			for (size_t j = 0; j < 26; j++)
			{
				string holder = key;
				holder.insert(i, 1, cArray[j]);
				if (current->search(holder))
				{
					cout << "Deletion error detected." << endl;
					cout << "Did you mean: " + holder + "?" << endl;
					check = true;
				}
			}
		}
		if (!check)
		{
			cout << "Sorry bro, your word does not exist or your spelling sucks." << endl;
			return false;
		}
		return true;
	}
}

const bool Trie::searchErrorSubstitution(string key)
{
	char cArray[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; // I know its probably not the best way
	bool check = false;
	Trie* current = this;
	if (current->search(key))
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < key.length(); i++)
		{
			for (size_t j = 0; j < 26; j++)
			{
				string holder = key;
				holder.replace(i, 1, 1, cArray[j]);
				if (current->search(holder))
				{
					cout << "Substitution error detected." << endl;
					cout << "Did you mean: " + holder + "?" << endl;
					check = true;
				}
			}
		}
		if (!check)
		{
			cout << "Sorry bro, your word does not exist or your spelling sucks." << endl;
			return false;
		}
		return true;
	}
}

const bool Trie::searchErrorTransposition(string key)
{
	bool check = false;
	Trie* current = this;
	if (current->search(key))
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < key.length() - 1; i++)
		{
			string holder = key;
			char val1 = holder.at(i);
			char val2 = holder.at(i + 1);
			holder.replace(i, 1, 1, val2);
			holder.replace(i + 1, 1, 1, val1);
			if (current->search(holder))
			{
				cout << "Transposition error detected." << endl;
				cout << "Did you mean: " + holder + "?" << endl;
				check = true;
			}
		}
		if (!check)
		{
			cout << "Sorry bro, your word does not exist or your spelling sucks." << endl;
			return false;
		}
		return true;
	}
}
