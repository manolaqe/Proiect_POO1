#pragma once
#include "Utilizator.h"
#include <map>
#include "Wrapper.h"

class Magazin: public Utilizator
{
protected:
	map<int, Wrapper> stocProduse;
public:
	Magazin(int, string, map<int, Wrapper>);

	void afiseazaProduse();

	void adaugaProdus(int, string, float, int);

	void stergeProdus(int);

	void modificaProdus(int, string);
	void modificaProdus(int idProdus, float pretProdus);
};

