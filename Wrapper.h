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

	friend ostream& operator<<(ostream& iesire, Wrapper& w);

};

