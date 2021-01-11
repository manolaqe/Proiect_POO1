#pragma once
#include <string>

using namespace std;

class Utilizator
{
protected:
	string username;
	string parola;

public:
	Utilizator(string username, string parola)
	{
		this->username = username;
		this->parola = parola;
	}

	bool autentificare(string username, string parola)
	{
		return (this->username == username && this->parola == parola);
	}
};

