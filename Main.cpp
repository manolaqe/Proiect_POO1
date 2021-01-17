#include <iostream>
#include <fstream>
#include <map>
#include "Magazin.h"
#include "Wrapper.h"
#include "Client.h"
#include "Produs.h"
#include <iomanip>


using namespace std;
Magazin magazin(1, "123");
Client client(2, "234", "Ionescu", "Gabriel", "Bucuresti, Sector 1, Verii, 8");

int AlegeOptiune()
{
	int optiune = -1;
	do
	{
		cout << right << setw(43) << "Optiune: ";
		cin >> optiune;
	} while (optiune == -1);


	return optiune;
}

int main()
{
	
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

		do {
			cout << right << setw(52) << endl << "Meniu principal Magazin" << endl;
			cout << "1 Afisare Stoc Produse" << endl;
			cout << "2 Editare Produse din Stoc" << endl;
			cout << "3 Stergere Produse din Stoc" << endl;
			cout << "4 Generare Raport Comenzi Primite" << endl;
			cout << "5 Prelucrare Comenzi Primite (selectarea curierului)" << endl;

			switch (AlegeOptiune())
			{
			case 1:
			{
				cout << "Produsele din stocul Magazinului: ";
				magazin.afiseazaProduse();
			}

			break;
			case 2: 
			{
				int ID;
				cout << "Editare Produse din Stoc " << endl;
				cout << "ID-ul produsului pe care doriti sa il modificati: " << endl;
				cin >> ID;
				cout << "0 Modificati numele produsului" << endl;
				cout << "1 Modificati pretul produsului" << endl;
				switch (AlegeOptiune()) {
				case 0:
				{
					magazin.returnProdusAfisare(ID);
					string numeNou;
					cout << "Introduceti numele nou pe care doriti sa il atribuiti produsului selectat: " << endl;
					cin >> numeNou;
					magazin.modificaProdus(ID, numeNou.c_str());
					magazin.returnProdusAfisare(ID);
					magazin.actualizareStoc();
				}
				break;
				case 1:
				{
					magazin.returnProdusAfisare(ID);
					float pretNou = 0.0f;
					cout << "Introduceti pretul nou pe care doriti sa il atribuiti produsului selectat: " << endl;
					cin >> pretNou;
					magazin.modificaProdus(ID, pretNou);
					magazin.returnProdusAfisare(ID);
					magazin.actualizareStoc();
				}
				break;
				}
			}
				break;
			case 3: {
				int ID;
				cout << "Stergere Produse din Stoc " << endl;
				cout << "ID-ul produsului pe care doriti sa il stergeti: " << endl;
				cin >> ID;
				cout << "0 Stergeti complet produsul din stoc" << endl;
				cout << "1 Modificati cantitatea stocata de produs" << endl;
				switch (AlegeOptiune())
				{
				case 0: 
				{
					cout << "Produsul: ";
					magazin.returnProdusAfisare(ID);
					cout << "a fost sters complet din stoc." << endl;
					magazin.stergeProdus(ID);
					magazin.actualizareStoc();
				}
				break;

				case 1: 
				{
					int cantitateNoua = 0;
					magazin.returnProdusAfisare(ID);
					cout << "Introduceti cantitatea actualizata a produsului selectat: " << endl;
					cin >> cantitateNoua;
					magazin.stergeProdus(ID, cantitateNoua);
					magazin.returnProdusAfisare(ID);
					magazin.actualizareStoc();
				}
				break;
				}
				
				
			}
				break;
			case 4: 
			{
				cout << "Rapoarte Comenzi Primite";
			}
				break;

			case 5: {
				int index = 0;
				int indexCurier = 0;
				cout << "Prelucrare comenzi primite" << endl; 
				magazin.afisareComenzi();
				cout << "Index comanda de prelucrat: " << endl;
				cin >> index;
				//de modificat enum etc etc etc
				cout << "\nIndex curier: " << endl;
				cin >> indexCurier;
				magazin.prelucrareComanda(index, indexCurier);
			}

				break;
			}
			cout << "\n0 Intoarce-te la meniul principal" << endl;
		} while (AlegeOptiune() == 0);
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

		do {
			cout << right << setw(52) << endl << "Meniu principal Client" << endl;
			cout << "1 Afisare Stoc Produse" << endl;
			cout << "2 Adaugare Produs in Cos" << endl;
			cout << "3 Afisare Produse din Cos" << endl;
			cout << "4 Stergere/Modificare Produs din Cos" << endl;
			cout << "5 Plasare Comanda" << endl;
			cout << "6 Raport Comanda" << endl;
			cout << "7 Afisare Date Personale Client" << endl;
			cout << "8 Modificare Date Personale Client" << endl;

			switch (AlegeOptiune())
			{
			case 1:
			{
				cout << "Produsele din stocul Magazinului: ";
				magazin.afiseazaProduse();
			}

			break;
			case 2:
			{
				do {
					int ID;
					int cantitate = 0;
					cout << "Adaugare produse in cos" << endl;
					cout << "ID-ul produsului pe care doriti sa il adaugati: " << endl;
					cin >> ID;
					cout << "\nCantitatea de produs pe care doriti sa o adaugati in cos: " << endl;
					cin >> cantitate;
					client.adaugaProdusinCos(magazin.returnProdus(ID), cantitate);
					cout << "0 Mai adauga un produs" << endl;
				} while (AlegeOptiune() == 0);
				
			}
			break;
			case 3: {
				cout << "Produsele pe care le aveti in cos: " << endl;
				client.afiseazaCos();
			}
				  break;
			case 4:
			{
				int ID;
				int cantitateProdus;
				cout << "Stergere/Modificare produs din cos: " << endl;
				cout << "ID-ul produsului pe care doriti sa il stergeti: " << endl;
				cin >> ID;
				cout << "0 Stergeti complet produsul din cos" << endl;
				cout << "1 Modificati cantitatea produsului din cos" << endl;
				switch (AlegeOptiune())
				{
				case 0:
				{
					client.stergeProdusdinCos(ID);
				}
				break;
				case 1:
				{
					cout << "Cantitatea de produs actualizata: " << endl;
					cin >> cantitateProdus;
					client.stergeProdusdinCos(ID, cantitateProdus);
				}
				break;
				}

			}
			break;

			case 5: 
			{
				cout << "Plasare Comanda..." << endl;
				magazin.plasareComanda(client.plaseazaComanda());
				cout << "Comanda a fost plasata!" << endl;
			}

				  break;

			case 6:
			{
				cout << "Generare Raport Comanda... " << endl;
				cout << "Raport generat in fisier text." << endl;
			}
				break;

			case 7:
			{
				cout << "Datele personale ale clientului: " << endl;
				cout << client;
			}
				break;

			case 8:
			{
				string nume = "";
				string prenume = "";
				string adresa = "";


			}
				break;

			}

			
			cout << "\n0 Intoarce-te la meniul principal" << endl;
		} while (AlegeOptiune() == 0);
	
	}
		break;
	}


	cin.get();

	return 0;
}