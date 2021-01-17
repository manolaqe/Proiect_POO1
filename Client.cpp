#include "Client.h"

Client::Client(int username, string parola, string nume, string prenume, string adresa): Utilizator(username, parola)
{
	this->nume = nume;
	this->prenume = prenume;
	this->adresa = adresa;
}

void Client::adaugaProdusinCos(Produs p, int cantitateProdus)
{
	cosProduse.insert({ p.getIdProdus(), Wrapper(p, cantitateProdus) });
}

void Client::stergeProdusdinCos(Produs p)
{
	cosProduse.erase(p.getIdProdus());
}

void Client::stergeProdusdinCos(Produs p, int cantitateProdus)
{		
	map<int, Wrapper>::iterator itStergere;
	itStergere = cosProduse.find(p.getIdProdus());
	itStergere->second.setCantitateProdus(cantitateProdus);
}

void Client::afiseazaCos()
{
	map<int, Wrapper>::iterator itStoc;
	for (itStoc = cosProduse.begin(); itStoc != cosProduse.end(); itStoc++)
	{
		cout << itStoc->first << "\t" << itStoc->second;
	}
}

vector<int> Client::produseinCos()
{
	vector<int> vect1;
	map<int, Wrapper>::iterator itStoc;
	for (itStoc = cosProduse.begin(); itStoc != cosProduse.end(); itStoc++)
	{
		vect1.push_back(itStoc->first);
	}

	return vect1;
}

Comanda Client::plaseazaComanda()
{
	return Comanda(username, cosProduse);
}
