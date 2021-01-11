#pragma once
#include "Utilizator.h"
#include <string>

using namespace std;

class Client: public Utilizator
{
protected:
	string nume;
	string prenume;
	string adresa;
	
public:
	Client(int username, string parola, string nume, string prenume, string adresa);
};

