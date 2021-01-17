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
	Curieri curier;
	map<int, Wrapper> produseComandate;

public:
	Comanda(int, map<int, Wrapper>);
	void setCurier(int c);
	map<int, Wrapper> getProduseComandate();
	friend ostream& operator<<(ostream& iesire, Comanda& c);
	friend ifstream& operator>>(ifstream& in, Comanda& c);
	friend ofstream& operator<<(ofstream& out, Comanda c);

};

