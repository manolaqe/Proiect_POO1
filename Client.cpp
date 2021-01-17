#include "Client.h"

Client::Client(int username, string parola, string nume, string prenume, string adresa): Utilizator(username, parola)
{
	this->nume = nume;
	this->prenume = prenume;
	this->adresa = adresa;
}

void Client::adaugaProdusinCos(Produs p, int cantitateProdus)
{

	if (cosProduse.count(p.getIdProdus()) == 0)
	{
		cosProduse.insert({ p.getIdProdus(), Wrapper(p, cantitateProdus) });
	}
	else if (cosProduse.find(p.getIdProdus())->second.getCantitateProdus() != 0)
	{
		cosProduse.find(p.getIdProdus())->second += cantitateProdus;

	}
}


void Client::stergeProdusdinCos(int idProdus, int cantitateProdus)
{		
	map<int, Wrapper>::iterator itStergere;
	itStergere = cosProduse.find(idProdus);
	itStergere->second.setCantitateProdus(cantitateProdus);
}

void Client::stergeProdusdinCos(int idProdus)
{
	cosProduse.erase(idProdus);
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

ostream& operator<<(ostream& iesire, Client& c)
{
	iesire << "Nume client: " << c.nume << endl;
	iesire << "Prenume client: " << c.prenume << endl;
	iesire << "Adresa client: " << c.adresa << endl;

	return iesire;
}

Client Client::setDatePersonale(string nume, string prenume, string adresa)
{
	if (nume != "")
	{
		this->nume = nume;
	}

	if (prenume != "")
	{
		this->prenume = prenume;
	}

	if (adresa != "")
	{
		this->adresa = adresa;
	}

}