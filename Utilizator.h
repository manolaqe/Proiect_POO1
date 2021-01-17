#pragma once
#include <string>

using namespace std;

//interfata

class Utilizator
{
protected:
	int username;
	string parola;

public:
	virtual bool autentificare(int username, string parola) = 0;
};

