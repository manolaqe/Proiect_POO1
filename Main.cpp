#include <iostream>
#include "Magazin.h"
#include <map>
#include "Wrapper.h"
#include "Client.h"

using namespace std;

void main()
{
	
	Magazin magazin(1, "123");

	magazin.adaugaProdus(100, "Paine", 2.0f, 5);
	magazin.adaugaProdus(101, "Lapte", 4.0f, 10);

	magazin.modificaProdus(100, 1.0f);
	cout << "produse din stoc: " << endl << endl;;
	magazin.afiseazaProduse();

	cout <<endl<< "produse din cos: " << endl;

	Client client(2, "234", "sff", "sfd", "sdfsf");
	client.adaugaProdusinCos(magazin.returnProdus(100), 2);
	client.adaugaProdusinCos(magazin.returnProdus(101), 3);
	client.stergeProdusdinCos(magazin.returnProdus(100), 1);
	client.afiseazaCos();
	magazin.plasareComanda(client.plaseazaComanda());
	cout << endl << "magazin actualizat dupa comanda: " << endl;
	magazin.afiseazaProduse();

	cout << endl << "comenzi efectuate: " << endl;
	magazin.afisareComenzi();
}