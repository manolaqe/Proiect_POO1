#include "Client.h"

Client::Client(int username, string parola, string nume, string prenume, string adresa): Utilizator(username, parola)
{
	this->nume = nume;
	this->prenume = prenume;
	this->adresa = adresa;
}
