#pragma once
#include "Utilizator.h"
#include <string>
#include <map>
#include "Wrapper.h"
#include "Magazin.h"
#include <vector>
#include "Comanda.h"

using namespace std;

class Client: public Utilizator
{
protected:
	string nume;
	string prenume;
	string adresa;
	map<int, Wrapper> cosProduse;
	
public:
	Client(int username, string parola, string nume, string prenume, string adresa); 

	void adaugaProdusinCos(Produs, int);

	void stergeProdusdinCos(Produs);

	void stergeProdusdinCos(Produs p, int cantitateProdus);

	void afiseazaCos();

	vector<int> produseinCos();

	Comanda plaseazaComanda();

//	void raportComanda();

};

