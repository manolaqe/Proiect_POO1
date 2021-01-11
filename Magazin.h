#pragma once
#include "Utilizator.h"

class Magazin: public Utilizator
{
protected:
	int a;
public:
	Magazin(int username, string parola);
};

