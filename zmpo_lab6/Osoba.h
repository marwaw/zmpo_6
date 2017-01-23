#pragma once
#include <string>
#include <iostream>
using namespace std;

class COsoba
{
public:
	COsoba();
	COsoba(string imie, int wiek);
	void setWiek(int wiek);
	string toString();
	~COsoba();

private:
	string *s_imie;
	int i_wiek;
};

