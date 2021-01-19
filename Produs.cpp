#include "Produs.h"

Produs::Produs()
{
	this->idProdus = 100;
	nrElemNume = strlen("produsNecunoscut");
	this->numeProdus = new char[strlen("produsNecunoscut") + 1];
	strcpy_s(this->numeProdus, strlen("produsNecunoscut") + 1 , "produsNecunoscut");
	this->pretProdus = 10.0f;
}

Produs::Produs(int idProdus, const char* numeProdus, float pretProdus)
{
	this->idProdus = idProdus;
	nrElemNume = strlen(numeProdus);
	this->numeProdus = new char[strlen(numeProdus) + 1];
	strcpy_s(this->numeProdus, strlen(numeProdus) + 1, numeProdus); 
	this->pretProdus = pretProdus;
}

Produs::Produs(const Produs& p)
{
	this->idProdus = p.idProdus;
	nrElemNume = strlen(p.numeProdus);
	this->numeProdus = new char[strlen(p.numeProdus) + 1];
	this->numeProdus = p.numeProdus;
	this->pretProdus = p.pretProdus;
}

void Produs::operator=(Produs p)
{
	this->idProdus = p.idProdus;
	nrElemNume = strlen(p.numeProdus);
	this->numeProdus = new char[strlen(p.numeProdus) + 1];
	this->numeProdus = p.numeProdus;
	this->pretProdus = p.pretProdus;
}

int Produs::getIdProdus()
{
	return this->idProdus;
}

const char* Produs::getNumeProdus()
{
	return this->numeProdus;
}

float Produs::getPretProdus()
{
	return this->pretProdus;
}

void Produs::setNumeProdus(const char* numeProdus)
{
	nrElemNume = strlen(numeProdus);
	this->numeProdus = new char[strlen(numeProdus) + 1];
	strcpy_s(this->numeProdus, strlen(numeProdus) + 1, numeProdus);
}

void Produs::setPretProdus(float pretProdus)
{
	this->pretProdus = pretProdus;
}
