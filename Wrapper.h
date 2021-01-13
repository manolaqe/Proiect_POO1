#pragma once
#include <iostream>
#include "Produs.h"

using namespace std;

class Wrapper
{
public:
	Produs produs;
	int cantitateProdus;

public:
	Wrapper(Produs produs, int cantitateProdus);
	
	Produs getProdus();
	
	int getCantitateProdus();

	void setCantitateProdus(int);

	friend ostream& operator<<(ostream& iesire, Wrapper& w);

	Wrapper();

};

