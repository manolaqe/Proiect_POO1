#include <iostream>
#include "Magazin.h"
#include <map>
#include "Wrapper.h"
#include "Client.h"
#include <fstream>
#include "Produs.h"

using namespace std;

void main()
{
	Wrapper a(Produs(100, "Paine franzela", 1.0f), 5);
	/*Wrapper b(Produs(101, "Lapte 1L", 6.0f), 15);
	Wrapper c(Produs(102, "Paine bagheta", 1.5f), 25);
	Wrapper d(Produs(103, "Pate Ficat Porc 210g", 3.0f), 54);
	Wrapper e(Produs(104, "Ton 300g", 14.0f), 34);
	Wrapper f(Produs(105, "Lamai 1kg", 5.0f), 21);
	Wrapper g(Produs(106, "File de somon 1kg", 30.0f), 12);
	Wrapper h(Produs(107, "Rosii 1kg", 3.0f), 60);
	Wrapper i(Produs(108, "Castraveti 1kg", 2.0f), 50);
	Wrapper j(Produs(109, "Pui 1kg", 20.0f), 32);
	Wrapper k(Produs(110, "Unt 180g", 19.5f), 23);
	Wrapper l(Produs(111, "Cafea 500g", 35.6f), 40);
	Wrapper m(Produs(112, "Ceai Tei", 5.0f), 80);
	Wrapper n(Produs(113, "Zahar 1kg", 7.2f), 34);
	Wrapper o(Produs(114, "Ulei 1L", 12.0f), 12);
	Wrapper p(Produs(115, "Iaurt de baut 350g", 4.0f), 14);
	Wrapper q(Produs(116, "Smantana 500g", 14.0f), 15);
	Wrapper r(Produs(117, "Cartofi 1kg", 3.0f), 100);
	Wrapper s(Produs(118, "Ceapa 1kg", 2.0f), 75);
	Wrapper t(Produs(119, "Sare 500g", 10.0f), 23);
	Wrapper u(Produs(120, "Iaurt natural 350g", 3.5f), 16);

	ofstream dateStoc("dateStoc.dat", ios::out | ios::binary);
	dateStoc.write((char*)&a, sizeof(Wrapper));
	dateStoc.write((char*)&b, sizeof(Wrapper));
	dateStoc.write((char*)&c, sizeof(Wrapper));
	dateStoc.write((char*)&d, sizeof(Wrapper));
	dateStoc.write((char*)&e, sizeof(Wrapper));
	dateStoc.write((char*)&f, sizeof(Wrapper));
	dateStoc.write((char*)&g, sizeof(Wrapper));
	dateStoc.write((char*)&h, sizeof(Wrapper));
	dateStoc.write((char*)&i, sizeof(Wrapper));
	dateStoc.write((char*)&j, sizeof(Wrapper));
	dateStoc.write((char*)&k, sizeof(Wrapper));
	dateStoc.write((char*)&l, sizeof(Wrapper));
	dateStoc.write((char*)&m, sizeof(Wrapper));
	dateStoc.write((char*)&n, sizeof(Wrapper));
	dateStoc.write((char*)&o, sizeof(Wrapper));
	dateStoc.write((char*)&p, sizeof(Wrapper));
	dateStoc.write((char*)&q, sizeof(Wrapper));
	dateStoc.write((char*)&r, sizeof(Wrapper));
	dateStoc.write((char*)&s, sizeof(Wrapper));
	dateStoc.write((char*)&t, sizeof(Wrapper));
	dateStoc.write((char*)&u, sizeof(Wrapper));*/

	ifstream dateStoc("dateStoc.dat", ios::binary);
	if (dateStoc.is_open())
	{
		dateStoc.seekg(0, ios::end);
		cout << "Numarul de elemente din fisierul selectat este: " << dateStoc.tellg() / sizeof(Wrapper) << endl;

		dateStoc.seekg(ios::beg);
		Wrapper aux;
		dateStoc.read((char*)&aux, sizeof(Wrapper));
		cout << "Elementele din fisier: ";
		while (!dateStoc.eof())
		{
			cout << aux;
			dateStoc.read((char*)&aux, sizeof(Wrapper));
		}
		cout << endl;

		dateStoc.close();
	}



	
	/*Magazin magazin(1, "123");

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
}