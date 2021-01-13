#pragma once
#include "Utilizator.h"
#include <map>
#include "Wrapper.h"
#include "Comanda.h"
#include <vector>

class Magazin: public Utilizator
{
protected:
	map<int, Wrapper> stocProduse;
	vector<Comanda> comenziEfectuate;
public:
	Magazin(int, string);

	void afiseazaProduse();

	void adaugaProdus(int, const char*, float, int);

	void stergeProdus(int);

	void modificaProdus(int, const char*);
	void modificaProdus(int idProdus, float pretProdus);

	Produs returnProdus(int);
	
	void plasareComanda(Comanda);

	void afisareComenzi();

//	void raportComenzi();
};

