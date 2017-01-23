#include "Osoba.h"



COsoba::COsoba()
{
}

COsoba::COsoba(string imie, int wiek)
{
	s_imie = new string(imie);
	i_wiek = wiek;
}

void COsoba::setWiek(int wiek)
{
	i_wiek = wiek;
}

string COsoba::toString()
{
	return "imie: " + *s_imie + " wiek: " + to_string(i_wiek);
}

COsoba::~COsoba()
{
	delete s_imie;
}
