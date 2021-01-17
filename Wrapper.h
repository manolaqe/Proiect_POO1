#pragma once
#include <iostream>
#include "Produs.h"
#include <fstream>

using namespace std;

class Wrapper
{
public:
	Produs produs;
	int cantitateProdus;

public:
	Wrapper(Produs produs, int cantitateProdus);

	Wrapper(int idProdus, const char* numeProdus, float pretProdus, int cantitateProdus);
	
	Produs getProdus();
	
	int getCantitateProdus();

	void setCantitateProdus(int);

	friend ostream& operator<<(ostream& iesire, Wrapper& w);

	Wrapper();

	Wrapper(const Wrapper& w);

	void serializare(ofstream& out, Wrapper w);

	Wrapper deserializare(ifstream& in);

	void operator+=(int cantitateProdus);

	friend ifstream& operator>>(ifstream& in, Wrapper& w);

	friend ofstream& operator<<(ofstream& out, Wrapper w);
};

