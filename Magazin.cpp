#include "Magazin.h"


Magazin::Magazin(int username, string parola, map<int, Wrapper> stocProduse): Utilizator(username, parola)
{
	this->stocProduse.insert(stocProduse.begin(), stocProduse.end());
}

void Magazin::afiseazaProduse()
{
	map<int, Wrapper>::iterator itStoc;
	for (itStoc = stocProduse.begin(); itStoc != stocProduse.end(); itStoc++)
	{
		cout << itStoc->first << "\t" << itStoc->second;
	}
}

void Magazin::adaugaProdus(int idProdus, string numeProdus, float pretProdus, int cantitateProdus)
{
	stocProduse.insert({ idProdus, Wrapper(Produs(idProdus, numeProdus, pretProdus), cantitateProdus) });
}

void Magazin::stergeProdus(int idProdus)
{
	stocProduse.erase(idProdus);
}

void Magazin::modificaProdus(int idProdus, string numeProdus)
{
	map<int, Wrapper>::iterator itModificare;
	itModificare = stocProduse.find(idProdus);
	itModificare->second.produs.setNumeProdus(numeProdus);
}

void Magazin::modificaProdus(int idProdus, float pretProdus)
{
	map<int, Wrapper>::iterator itModificare;
	itModificare = stocProduse.find(idProdus);
	itModificare->second.produs.setPretProdus(pretProdus);
}
