#pragma once
#include <iostream>
#include <string>

using namespace std;
class Produs
{
public:
	int idProdus;
	char* numeProdus;
	float pretProdus;
	int nrElemNume;

public:
	Produs();
	Produs(int, const char*, float);
	Produs(const Produs& p);
	void operator=(Produs);
	int getIdProdus();
	const char* getNumeProdus();
	float getPretProdus();
	void setNumeProdus(const char* numeProdus);
	void setPretProdus(float pretProdus);



};

