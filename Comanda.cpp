#include "Comanda.h"

Comanda::Comanda(int idClient, map<int, Wrapper> produseComandate)
{
	this->idClient = idClient;
	this->produseComandate.insert(produseComandate.begin(), produseComandate.end());
	//map<int, Wrapper>::iterator itInserare;
	/*for (itInserare = produseComandate.begin(); itInserare != produseComandate.end(); itInserare++)
		this->valoareComanda += itInserare->second.produs.getPretProdus() * itInserare->second.getCantitateProdus();*/
	curier = Curieri::Default;
}

void Comanda::setCurier(int c)
{
	curier = Curieri(c);
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

	iesire << ". Comanda va fi livrata cu ";

	switch (c.curier)
	{
	case Curieri::Default: iesire << "Curier default";
		break;
	case Curieri::DPD: iesire << "DPD";
		break;
	case Curieri::FanCurier: iesire << "FanCurier";
		break;
	case Curieri::PostaRomana: iesire << "PostaRomana";
		break;
	case Curieri::UrgentCargus: iesire << "UrgentCargus";
		break;
	}


	return iesire;
}

ifstream& operator>>(ifstream& in, Comanda& c)
{
	/*in.read((char*)&c.idClient, sizeof(int));
	in.read((char*)&c.curier, sizeof(Curieri));
	in.read((char*)&c.)
	*/
	return in;
}

ofstream& operator<<(ofstream& out, Comanda c)
{

	return out;
}