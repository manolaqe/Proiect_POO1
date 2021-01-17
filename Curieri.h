#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Curieri {

protected:
	vector<string> EnumCurieri = { "Default", "FanCurier", "DPD", "UrgentCargus", "PostaRomana" };
	

public:
	int index = 0;
	string curier = EnumCurieri[index];

	Curieri();
	Curieri(int index);
	friend ostream& operator<<(ostream& iesire, Curieri& c);
	string toString();
	void setCurier(int index);
	int getIndex();

};

