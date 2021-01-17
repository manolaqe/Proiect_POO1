#include <iostream>
#include <fstream>
#include <map>
#include "Magazin.h"
#include "Wrapper.h"
#include "Client.h"
#include "Produs.h"
#include <iomanip>


using namespace std;

int AlegeOptiune()
{
	int optiune = 0;
	do
	{
		cout << right << setw(43) << "Optiune: ";
		cin >> optiune;
	} while (optiune == 0);


	return optiune;
}

int main()
{
	Magazin magazin(1, "123");
	Client client(2, "234", "Ionescu", "Gabriel", "Bucuresti, Sector 1, Verii, 8");
	Wrapper aux;
	vector<Wrapper> vect;
	//map <int, Wrapper> mapul;
	/*vector<Wrapper> vectorWrapper = {Wrapper(Produs(100, "Paine franzela", 1.0f), 5),
		Wrapper(Produs(101, "Lapte 1L", 6.0f), 15), Wrapper(Produs(102, "Paine bagheta", 1.5f), 25), Wrapper(Produs(103, "Pate Ficat Porc 210g", 3.0f), 54),
		Wrapper(Produs(104, "Ton 300g", 14.0f), 34), Wrapper(Produs(105, "Lamai 1kg", 5.0f), 21), Wrapper(Produs(106, "File de somon 1kg", 30.0f), 12),
		Wrapper(Produs(107, "Rosii 1kg", 3.0f), 60), Wrapper(Produs(108, "Castraveti 1kg", 2.0f), 50), Wrapper(Produs(109, "Pui 1kg", 20.0f), 32), 
		Wrapper(Produs(110, "Unt 180g", 19.5f), 23), Wrapper(Produs(111, "Cafea 500g", 35.6f), 40), Wrapper(Produs(112, "Ceai Tei", 5.0f), 80), 
		Wrapper(Produs(113, "Zahar 1kg", 7.2f), 34), Wrapper(Produs(114, "Ulei 1L", 12.0f), 12), Wrapper(Produs(115, "Iaurt de baut 350g", 4.0f), 14),
		Wrapper(Produs(116, "Smantana 500g", 14.0f), 15), Wrapper(Produs(117, "Cartofi 1kg", 3.0f), 100), Wrapper(Produs(118, "Ceapa 1kg", 2.0f), 75),
		Wrapper(Produs(119, "Sare 500g", 10.0f), 23), Wrapper(Produs(120, "Iaurt natural 350g", 3.5f), 16) };*/


	//ofstream dateStoc("dateStoc1.dat", ios::binary);
	//if (dateStoc.is_open()) {
	//	for (int i = 0; i < 21; i++)
	//	{
	//		dateStoc << vectorWrapper[i];
	//	}
	//	dateStoc.close();
	//}

	//

	ifstream dateStoc1("dateStoc1.dat", ios::binary);
	if (dateStoc1.is_open())
	{
		dateStoc1.seekg(0, ios::beg);


		while (!dateStoc1.eof())
		{
			dateStoc1 >> aux;
			magazin.adaugaProdus(Wrapper(aux.produs.idProdus, aux.produs.numeProdus, aux.produs.pretProdus, aux.cantitateProdus));
		}
		cout << endl;
		dateStoc1.close();
	}

	//magazin.afiseazaProduse();
	


	cout << right << setw(53) <<"]-MAGAZIN ALIMENTAR ONLINE-[" << endl<<endl;
	cout << "================================================================================" << endl << endl;
	cout << right << setw(52) << "Alegeti tipul de utilizator" << endl << endl;
	cout << right << setw(43) << "1 Magazin" << endl << endl;
	cout << right << setw(42) << "2 Client" << endl << endl;
	cout << "================================================================================" << endl << endl;
	
	int username;
	string parola;

	switch (AlegeOptiune())
	{
	case 1: 
	{
		do {
			
			cout << right << setw(47) << endl << "Ati ales Magazin" << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << right << setw(44) << "Username: ";
			cin >> username;
			cout << right << setw(43) << "Parola: ";
			cin >> parola;
		} while (!magazin.autentificare(username, parola));

		cout << right << setw(52) << endl << "Meniul principal Magazin" << endl;
		cout <<  "1 Afisare Stoc Produse"<<endl;
		cout <<  "2 Editare Produse din Stoc" << endl;
		cout <<  "3 Stergere Produse din Stoc" << endl;
		cout <<  "4 Generare Raport Comenzi Primite" << endl;

		switch (AlegeOptiune())
		{
			do {} while ();

		}
	}
		break;
	case 2: 
	{
		do {

			cout << right << setw(46) << "Ati ales Client" << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << right << setw(44) << "Username: ";
			cin >> username;
			cout << right << setw(43) << "Parola: ";
			cin >> parola;
		} while (!client.autentificare(username, parola));

	}
		break;
	}


	cin.get();

	return 0;
}