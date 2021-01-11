#pragma once
#include <string>

using namespace std;

class Utilizator
{
protected:
	int username;
	string parola;

public:
	Utilizator(int username, string parola);
	bool autentificare(int username, string parola);
};

