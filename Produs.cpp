#include "Produs.h"

Produs::Produs()
{
	this->idProdus = 100;
	this->numeProdus = "produsNecunoscut";
	this->pretProdus = 10.0f;
}

Produs::Produs(int idProdus = 100, const char* numeProdus = "produsNecunoscut", float pretProdus = 10.0f)
{
	this->idProdus = idProdus;
	this->numeProdus = numeProdus;
	this->pretProdus = pretProdus;
}

void Produs::operator=(Produs p)
{
	this->idProdus = p.idProdus;
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
	this->numeProdus = numeProdus;
}

void Produs::setPretProdus(float pretProdus)
{
	this->pretProdus = pretProdus;
}
