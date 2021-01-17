#include "Curieri.h"

Curieri::Curieri()
{
	this->curier = EnumCurieri[this->index];
}

Curieri::Curieri(int index)
{
	this->index = index;
	this->curier = EnumCurieri[this->index];
}

string Curieri::toString()
{
	return curier;
}

void Curieri::setCurier(int index)
{
	this->index = index;
	this->curier = EnumCurieri[this->index];
}

int Curieri::getIndex()
{
	return index;
}

ostream& operator<<(ostream& iesire, Curieri& c)
{
	iesire << c.curier;
	return iesire;
}
