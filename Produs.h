#pragma once
#include <iostream>

using namespace std;
class Produs
{
protected:
	int idProdus;
	const char* numeProdus;
	float pretProdus;
public:
	Produs();
	Produs(int, const char*, float);
	void operator=(Produs);
	int getIdProdus();
	const char* getNumeProdus();
	float getPretProdus();
	void setNumeProdus(const char* numeProdus);
	void setPretProdus(float pretProdus);
};

