#include <iostream>
#include <fstream>
#include <map>
#include "Magazin.h"
#include "Wrapper.h"
#include "Client.h"
#include "Produs.h"

using namespace std;

int main()
{
	Magazin magazin(1, "123");
	Client client(2, "234", "Ionescu", "Gabriel", "Bucuresti, Sector 1, Verii, 8");

	Wrapper vectorWrapper[] = { Wrapper(Produs(100, "Paine franzela", 1.0f), 5), Wrapper(Produs(100, "Paine franzela", 1.0f), 5),
		Wrapper(Produs(101, "Lapte 1L", 6.0f), 15), Wrapper(Produs(102, "Paine bagheta", 1.5f), 25), Wrapper(Produs(103, "Pate Ficat Porc 210g", 3.0f), 54),
		Wrapper(Produs(104, "Ton 300g", 14.0f), 34), Wrapper(Produs(105, "Lamai 1kg", 5.0f), 21), Wrapper(Produs(106, "File de somon 1kg", 30.0f), 12),
		Wrapper(Produs(107, "Rosii 1kg", 3.0f), 60), Wrapper(Produs(108, "Castraveti 1kg", 2.0f), 50), Wrapper(Produs(109, "Pui 1kg", 20.0f), 32), 
		Wrapper(Produs(110, "Unt 180g", 19.5f), 23), Wrapper(Produs(111, "Cafea 500g", 35.6f), 40), Wrapper(Produs(112, "Ceai Tei", 5.0f), 80), 
		Wrapper(Produs(113, "Zahar 1kg", 7.2f), 34), Wrapper(Produs(114, "Ulei 1L", 12.0f), 12), Wrapper(Produs(115, "Iaurt de baut 350g", 4.0f), 14),
		Wrapper(Produs(116, "Smantana 500g", 14.0f), 15), Wrapper(Produs(117, "Cartofi 1kg", 3.0f), 100), Wrapper(Produs(118, "Ceapa 1kg", 2.0f), 75),
		Wrapper(Produs(119, "Sare 500g", 10.0f), 23), Wrapper(Produs(120, "Iaurt natural 350g", 3.5f), 16) };

	ofstream dateStoc("dateStoc1.bin", ios::out | ios::binary);
	for (int i = 0; i < 20; i++)
	{
		dateStoc.write((char*)&vectorWrapper[i], sizeof(Wrapper));
	}

	dateStoc.close();
	
	Wrapper aux;
	ifstream dateStoc1("dateStoc1.bin", ios::in | ios::binary);
	if (dateStoc1.is_open())
	{	
		dateStoc1.seekg(ios::beg);
		
		dateStoc1.read((char*)&aux, sizeof(Wrapper));
		
		while (!dateStoc1.eof())
		{
			magazin.adaugaProdus(aux.getProdus().getIdProdus(), aux.getProdus().getNumeProdus(), aux.getProdus().getPretProdus(), aux.getCantitateProdus());
			dateStoc1.read((char*)&aux, sizeof(Wrapper));
		}
		cout << endl;
		dateStoc1.close();
	}

	int optiune = 0;

	cout << "Alegeti tipul de utilizator: ";
	cout << "\n1 Magazin \n2 Client";

	do {
		cout << "\nOptiune: ";
		cin >> optiune;
	} while (optiune == 0);

	if (optiune == 1)
	{
		cout << "\nAti ales modul Magazin!";
	}
	else if (optiune == 2)
	{
		optiune = 0;
		cout << "Ati ales modul Client!";
		cout << "\nMeniu: ";
		cout << "\n1 Vezi produsele pe care le poti cumpara" << "\n2 Adauga un produs in cos" << "\n3 Sterge un produs din cos" << "\n4 Vezi cos" << "\n5 Plaseaza o comanda" << "\n6 Raport comanda";
		do {
			cout << "\nOptiune: ";
			cin >> optiune;
		
			switch (optiune)
			{
			case 1:magazin.afiseazaProduse();
				break;
			case 2: {
				int id;
				int cant;
				cout << "\nIntroduceti id-ul produsului pe care doriti sa il adaugati: ";
				cin >> id;
				cout << "\nIntroduceti cantitatea de produs: ";
				cin >> cant;
				client.adaugaProdusinCos(magazin.returnProdus(id), cant);
			};
				  break;
			case 3: {
				int id;
				int cant;
				cout << "\nIntroduceti id-ul produsului pe care doriti sa il stergeti: ";
				cin >> id;
				cout << "\nIntroduceti cantitatea de produs: ";
				cin >> cant;
				client.stergeProdusdinCos(magazin.returnProdus(id), cant);
			};
			case 4: {
				client.afiseazaCos();
			};
			}
		} while (optiune == 0);

		
	}
	/*
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
	magazin.afisareComenzi();*/

	cin.get();

	return 0;
}