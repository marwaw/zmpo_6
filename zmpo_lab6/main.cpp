#include "Tab.h"
#include "Osoba.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	/*
	CTab<int> i_tab;
	cout<<i_tab.sGetName()<<endl;
	i_tab.vSetElement(0, new int(0));
	cout<<*i_tab.getElement(0)<<endl;
	try {
		cout << *i_tab.getElement(100) << endl;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	*/
	const int _DEF_SIZE = 100;
	CTab<int> **cPointers = new CTab<int>*[_DEF_SIZE];
	for (int i = 0; i < _DEF_SIZE; i++)
	{
		cPointers[i] = nullptr;
	}

	string command = "";

	while (command != "quit")
	{
		cin >> command;

		if (command == "createDef")
		{
			int tableNr;
			cin >> tableNr;
			cPointers[tableNr] = new CTab<int>();
			cout << "done" << endl;
		}//if (command == "createDef")

		else if (command == "create")
		{
			int tableNr, size;
			string tableName;
			cin >> tableNr >> size >> tableName;
			cPointers[tableNr] = new CTab<int>(tableName);
			cPointers[tableNr]->iResizeTable(size);
			cout << "done" << endl;
		}//else if (command == "create")
/*
		else if (command == "createCopy")
		{
			int tableNr, i_table_to_copy;
			cin >> tableNr >> i_table_to_copy;
			cPointers[tableNr] = new CTab<int>(*cPointers[i_table_to_copy]);
			cout << "done" << endl;
		}//else if (command == "createCopy")
*/
		else if (command == "setValue")
		{
			int tableNr, index, value;
			cin >> tableNr >> index >> value;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				cPointers[tableNr]->vSetElement(index, new int(value));
				cout << "done" << endl;
			}
		}//else if (command == "setValue")

		else if (command == "getValue")
		{
			int tableNr, index;
			cin >> tableNr >> index;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				int piSucc = 0;
				int x = *cPointers[tableNr]->getElement(index);
				if (piSucc < 0) cout << "not done" << endl;
				else
				{
					cout << "Element z tablicy nr " << to_string(tableNr) << " o indeksie " << to_string(index) << " : " << to_string(x) << endl;
				}
			}

		}//else if (command == "getValue")

		else if (command == "setName")
		{
			int tableNr;
			string tableName;
			cin >> tableNr >> tableName;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				cPointers[tableNr]->vSetName(tableName);
				cout << "done" << endl;
			}
		}//else if (command == "setName")

		else if (command == "getName")
		{
			int tableNr;
			cin >> tableNr;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				cout << "Nazwa tablicy o nr " << to_string(tableNr) << " : " << cPointers[tableNr]->sGetName() << endl;
			}
		}//else if (command == "getName")

		else if (command == "setSize")
		{
			int tableNr, size;
			cin >> tableNr >> size;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				if (cPointers[tableNr]->iResizeTable(size) < 0) cout << "not done" << endl;
				else cout << "done" << endl;
			}
		}//else if (command == "setSize")

		else if (command == "delete")
		{
			int tableNr;
			cin >> tableNr;
			if (cPointers[tableNr] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				//cPointers[tableNr]->~CTab();
				//cPointers[tableNr] = NULL;
				delete cPointers[tableNr];
				cPointers[tableNr] = NULL;
				cout << "done" << endl;

			}
		}//else if (command == "delete")

		else if (command == "deleteAll" || command == "quit")
		{
			for (int i = 0; i < _DEF_SIZE; i++)
			{
				if (cPointers[i])
				{
					delete cPointers[i];
					//cPointers[i]->~CTab();
					cPointers[i] = NULL;
				}
			}
			if (command == "quit")
			{
				delete[] cPointers;
				cPointers = NULL;
			}
			cout << "done" << endl;
		}//else if (command == "deleteAll")

		/*
		else if (command == "display")
		{
			int tableNumber;
			cin >> tableNumber;
			if (cPointers[tableNumber] == NULL)
			{
				cout << "Tablica o podanym numerze nie istnieje." << endl;
			}
			else
			{
				cout << cPointers[tableNumber]->sInfo() << endl;
			}
		}//else if (command == "display")
		*/
		else
		{
			cout << "Cos poszlo nie tak. Sprobuj jeszcze raz." << endl;
		}
	}

	cin.ignore();
	return 0;
}