#include "Magazin.h"


Magazin::Magazin(int username, string parola): Utilizator(username, parola)
{
	
}

void Magazin::afiseazaProduse()
{
	map<int, Wrapper>::iterator itStoc;
	for (itStoc = stocProduse.begin(); itStoc != stocProduse.end(); itStoc++)
	{
		cout << itStoc->first << "\t" << itStoc->second;
	}
}

void Magazin::adaugaProdus(int idProdus, const char* numeProdus, float pretProdus, int cantitateProdus)
{
	stocProduse.insert({ idProdus, Wrapper(Produs(idProdus, numeProdus, pretProdus), cantitateProdus) });
}

void Magazin::stergeProdus(int idProdus)
{
	stocProduse.erase(idProdus);
}

void Magazin::modificaProdus(int idProdus, const char* numeProdus)
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

Produs Magazin::returnProdus(int idProdus)
{
	map<int, Wrapper>::iterator itReturnare;
	itReturnare = stocProduse.find(idProdus);
	return itReturnare->second.produs;
}

void Magazin::plasareComanda(Comanda comanda)
{
	map<int, Wrapper> comandaCos = comanda.produseComandate;
	comenziEfectuate.push_back(comanda);

	map<int, Wrapper>::iterator itStoc = stocProduse.begin();
	map<int, Wrapper>::iterator itCos = comandaCos.begin();

	for (itCos = comandaCos.begin(); itCos != comandaCos.end(); itCos++)
	{
		itStoc = stocProduse.find(itCos->first);
		itStoc->second.setCantitateProdus(itStoc->second.getCantitateProdus() - itCos->second.getCantitateProdus());
	}

}

void Magazin::afisareComenzi()
{
	for (int i = 0; i < comenziEfectuate.size(); i++)
		cout << comenziEfectuate[i];
}
