#include "Comanda.h"

Comanda::Comanda(int idClient, map<int, Wrapper> produseComandate)
{
	this->idClient = idClient;
	this->produseComandate.insert(produseComandate.begin(), produseComandate.end());
	
}

void Comanda::setCurier(int c)
{
	curier.setCurier(c);
}

map<int, Wrapper> Comanda::getProduseComandate()
{
	return this->produseComandate;
}

ostream& operator<<(ostream& iesire, Comanda& c)
{
	float valoareComanda = 0.0f;
	map<int, Wrapper>::iterator itAfisare = c.produseComandate.begin();
	for (itAfisare = c.produseComandate.begin(); itAfisare != c.produseComandate.end(); itAfisare++)
		valoareComanda += itAfisare->second.produs.getPretProdus() * itAfisare->second.getCantitateProdus();
	iesire << "Comanda efectuata de clientul " <<  " cu username-ul " << c.idClient << ". Valoare: " << valoareComanda <<". Produse comandate: " << endl;

	for (itAfisare = c.produseComandate.begin(); itAfisare != c.produseComandate.end(); itAfisare++)
	{
		iesire << itAfisare->second;
	}

	iesire << ". Comanda va fi livrata cu " << c.curier;

	return iesire;
}

ifstream& operator>>(ifstream& in, Comanda& c)
{
	in.read((char*)&c.idClient, sizeof(int));
	in.read((char*)&c.curier.index, sizeof(int));
	c.setCurier(c.curier.index);
	map<int, Wrapper>::iterator itCitire;
	for (itCitire = c.produseComandate.begin(); itCitire != c.produseComandate.end(); itCitire++)
		in >> itCitire->second;
	
	return in;
}

ofstream& operator<<(ofstream& out, Comanda c)
{
	out.write((char*)&c.idClient, sizeof(int));
	out.write((char*)&c.curier.index, sizeof(int));
	map<int, Wrapper>::iterator itScriere;
	for (itScriere = c.produseComandate.begin(); itScriere != c.produseComandate.end(); itScriere++)
		out << itScriere->second;

	return out;
}