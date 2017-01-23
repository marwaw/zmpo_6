#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <class T>
class CTab
{
public:
	CTab();
	CTab(string sname);
	CTab(CTab &pc_other);
	~CTab();
	int iResizeTable(int size);
	void vSetName(string sName);
	string sGetName();
	void vSetElement(int index, T *value);
	T* getElement(int index);
	CTab<T>* cClone();
	void vCloneFromBtoA(CTab &A, CTab &B);
	T**iCloneTable(T**pcOther, int size);

private:
	string s_name;
	T **p_table;
	int tableSize;
	const int DEF_TABLE_SIZE = 5;
	const string DEF_TABLE_NAME = "table";
	T* DEF_VALUE = nullptr;

};


template<class T>
CTab<T>::CTab()
{
	s_name = DEF_TABLE_NAME;
	tableSize = DEF_TABLE_SIZE;
	p_table = new T*[tableSize];
	
	for (int i = 0; i < DEF_TABLE_SIZE; i++)
	{
		p_table[i] = DEF_VALUE;
	}
	cout << "bezp: " << s_name << endl;
	
}


template<class T>
CTab<T>::CTab(string sname)
{
	s_name = sname;
	tableSize = DEF_TABLE_SIZE;
	p_table = new T*[tableSize];
	for (int i = 0; i < DEF_TABLE_SIZE; i++)
	{
		p_table[i] = DEF_VALUE;
	}
	cout << "parametr: " << s_name << endl;
}

template<class T>
CTab<T>::CTab(CTab &pc_other)
{
	s_name = pcOther.s_name + "_copy";
	tableSize = pcOther.tableSize;
	p_table = new T*[tableSize];
	vCloneFromBtoA(*this, pcOther);
	cout << "kopiuj: " << s_name << endl;
}

template<class T>
CTab<T>::~CTab()
{
	for (int i = 0; i < tableSize; i++)
	{
		delete p_table[i];
	}
	delete p_table;
}

template<class T>
int CTab<T>::iResizeTable(int size)
{
	if (size < 0) return -1;
	else
	{
		T **p_new_table = new T*[size];

		for (int i = 0; i < size; i++)
		{
			p_new_table[i] = DEF_VALUE;
		}

		for (int i = 0; i < size && i < tableSize; i++)
		{
			p_new_table[i] = p_table[i];
		}

		tableSize = size;
		delete[] p_table;
		p_table = p_new_table;
		return 1;
	}
}

template<class T>
void CTab<T>::vSetName(string sName)
{
	s_name = sName;
}

template<class T>
string CTab<T>::sGetName()
{
	return s_name;
}


template<class T>
CTab<T>* CTab<T>::cClone()
{
	CTab *clone = new CTab(*this);
	clone->s_name = s_name;
	return *clone;
}


template<class T>
void CTab<T>::vCloneFromBtoA(CTab &A, CTab &B)
{
	A.tableSize = B.tableSize;
	delete[] A.p_table;
	A.p_table = iCloneTable(B.p_table, B.tableSize);
}

template<class T>
T** CTab<T>::iCloneTable(T ** pcOther, int size)
{
	T **p_new_table = new T*[size];
	for (int i = 0; i < size; i++)
	{
		p_new_table[i] = pcOther[i];
	}
	return p_new_table;
}

template<class T>
void CTab<T>::vSetElement(int index, T *value)
{
	if (index < 0 || index > tableSize - 1) throw "Index out of bounds!";
	else
	{
		p_table[index] = value;
	}
}

template<class T>
T* CTab<T>::getElement(int index)
{
	if (index < 0 || index > tableSize - 1) throw "Index out of bounds!";
	return p_table[index];
}
