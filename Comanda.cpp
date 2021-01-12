#include "Comanda.h"

Comanda::Comanda(int idClient, string numeDestinatar, string prenumeDestinatar, string adresaDestinatie, map<int, Wrapper> produseComandate)
{
	this->idClient = idClient;
	this->numeDestinatar = numeDestinatar;
	this->prenumeDestinatar = prenumeDestinatar;
	this->adresaDestinatie = adresaDestinatie;
	this->produseComandate.insert(produseComandate.begin(), produseComandate.end());
	map<int, Wrapper>::iterator itInserare;
	for (itInserare = produseComandate.begin(); itInserare != produseComandate.end(); itInserare++)
		this->valoareComanda += itInserare->second.produs.getPretProdus() * itInserare->second.getCantitateProdus();
	curier = Curieri::Default;
}

void Comanda::setCurier(Curieri curier)
{
	this->curier = curier;
}

map<int, Wrapper> Comanda::getProduseComandate()
{
	return this->produseComandate;
}

ostream& operator<<(ostream& iesire, Comanda& c)
{
	map<int, Wrapper>::iterator itAfisare = c.produseComandate.begin();
	iesire << "Comanda efectuata de clientul " << c.numeDestinatar << " " << c.prenumeDestinatar << " cu username-ul " << c.idClient << ". Valoare: " << c.valoareComanda << ". Produse comandate: " << endl;
	for (itAfisare = c.produseComandate.begin(); itAfisare != c.produseComandate.end(); itAfisare++)
	{
		iesire << itAfisare->second;
	}

	return iesire;
}
