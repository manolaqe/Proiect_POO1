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

	void adaugaProdus(Wrapper w);

	void stergeProdus(int);

	void stergeProdus(int idProdus, int cantitate);

	void modificaProdus(int, const char*);
	void modificaProdus(int idProdus, float pretProdus);

	Produs returnProdus(int);

	void returnProdusAfisare(int idProdus);
	
	void plasareComanda(Comanda);

	void afisareComenzi();

	void actualizareStoc();

	void actualizareComenzi();

	void prelucrareComanda(int index, int curier);



//	void raportComenzi();
};

