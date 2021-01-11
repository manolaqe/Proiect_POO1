#include "Utilizator.h"

Utilizator::Utilizator(int username, string parola)
{
	this->username = username;
	this->parola = parola;
}

bool Utilizator::autentificare(int username, string parola)
{
	return (this->username == username) && (this->parola == parola);
}

