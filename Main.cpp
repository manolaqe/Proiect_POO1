#include <iostream>
#include "Magazin.h"
#include <map>
#include "Wrapper.h"
using namespace std;

void main()
{
	map<int, Wrapper> stocProduse;
	Magazin magazin(1, "123", stocProduse);
	magazin.afiseazaProduse();
	magazin.adaugaProdus(100, "Paine", 2.0f, 5);
	magazin.afiseazaProduse();
	magazin.modificaProdus(100, 1.0f);
	magazin.afiseazaProduse();
	magazin.stergeProdus(100);
	magazin.afiseazaProduse();
}