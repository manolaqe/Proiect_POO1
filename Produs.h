#pragma once
#include <iostream>

using namespace std;
class Produs
{
protected:
	int idProdus;
	string numeProdus;
	float pretProdus;
public:
	Produs();
	Produs(int, string, float);
	void operator=(Produs);
	int getIdProdus();
	string getNumeProdus();
	float getPretProdus();
	void setNumeProdus(string numeProdus);
};

