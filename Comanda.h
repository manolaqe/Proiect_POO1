#pragma once
#include <iostream>
#include "Curieri.h"
#include <map>
#include "Wrapper.h"
using namespace std;

class Comanda
{
public:
	int idClient;
	string numeDestinatar;
	string prenumeDestinatar;
	string adresaDestinatie;
	Curieri curier;
	float valoareComanda = 0;
	map<int, Wrapper> produseComandate;

public:
	Comanda(int, string, string, string, map<int, Wrapper>);
	void setCurier(Curieri);
	map<int, Wrapper> getProduseComandate();
	friend ostream& operator<<(ostream& iesire, Comanda& c);

};

