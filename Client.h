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

	void stergeProdusdinCos(int idProdus);

	void stergeProdusdinCos(int idProdus, int cantitateProdus);

	void afiseazaCos();

	vector<int> produseinCos();

	Comanda plaseazaComanda();

	void setNume(string nume);

	void setPrenume(string prenume);

	void setAdresa(string adresa);



	void AfisareDatePersonale();
	
	friend ostream& operator<<(ostream& iesire, Client& c);
	


//	void raportComanda();

};

