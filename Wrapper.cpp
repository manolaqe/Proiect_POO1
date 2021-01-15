#include "Wrapper.h"

Wrapper::Wrapper(Produs produs, int cantitateProdus)
{
	this->produs = produs;
	this->cantitateProdus = cantitateProdus;
}

Wrapper::Wrapper(int idProdus, const char* numeProdus, float pretProdus, int cantitateProdus)
{
	this->produs.idProdus = idProdus;
	this->produs.nrElemNume = strlen(numeProdus);
	this->produs.numeProdus = new char[strlen(numeProdus) + 1];
	strcpy_s(this->produs.numeProdus, strlen(numeProdus) + 1, numeProdus);
	this->produs.pretProdus = pretProdus;
	this->cantitateProdus = cantitateProdus;
}

Produs Wrapper::getProdus()
{
	return produs;
}

int Wrapper::getCantitateProdus()
{
	return this->cantitateProdus;
}

void Wrapper::setCantitateProdus(int cantitateProdus)
{
	this->cantitateProdus = cantitateProdus;
	if (this->cantitateProdus <= 0)
	{
		this->produs = Produs();
		cantitateProdus = -1;
	}
}

Wrapper::Wrapper()
{
	Produs p(99, "ProdusNecunoscut", 2.3f);
	this->produs = p;
	this->cantitateProdus = 3;
}

Wrapper::Wrapper(const Wrapper& w)
{
	cantitateProdus = w.cantitateProdus;
	produs = w.produs;
}

ostream& operator<<(ostream& iesire, Wrapper& w)
{
	//iesire << "numeProdus.push_back(" << w.produs.getNumeProdus() << ");";
	iesire << " \nPRODUS:" << w.produs.numeProdus << "\nID: " << w.produs.idProdus << "\n" << "PRET: " << w.produs.pretProdus << "\nCANTITATE: " << w.cantitateProdus << endl;
	return iesire;
}

void Wrapper::serializare(ofstream& out, Wrapper w)
{
	out.write((char*)&w.produs.idProdus, sizeof(int));
	out.write((char*)&w.produs.nrElemNume, sizeof(int));
	out.write(w.produs.numeProdus, w.produs.nrElemNume * sizeof(char));
	out.write((char*)&w.produs.pretProdus, sizeof(float));
	out.write((char*)&w.cantitateProdus, sizeof(int));
	out.flush();
}

Wrapper Wrapper::deserializare(ifstream& in)
{
	Wrapper aux;
	in.read(reinterpret_cast<char*>(&aux), sizeof(Wrapper));
	return aux;
}

ifstream& operator>>(ifstream& in, Wrapper& w)
{
	delete[] w.produs.numeProdus;
	in.read((char*)&w.produs.nrElemNume, sizeof(int));
	w.produs.numeProdus = new char[w.produs.nrElemNume + 1];
	int size = (w.produs.nrElemNume + 1) * sizeof(char);
	in.read(w.produs.numeProdus, size);

	in.read((char*)&w.produs.idProdus, sizeof(int));
	in.read((char*)&w.produs.pretProdus, sizeof(float));
	in.read((char*)&w.cantitateProdus, sizeof(int));

	return in;
}

ofstream& operator<<(ofstream& out, Wrapper w)
{
	
	out.write((char*)&w.produs.nrElemNume, sizeof(int));
	int size = (w.produs.nrElemNume + 1) * sizeof(char);
	out.write(w.produs.numeProdus, size);
	out.write((char*)&w.produs.idProdus, sizeof(int));
	out.write((char*)&w.produs.pretProdus, sizeof(float));
	out.write((char*)&w.cantitateProdus, sizeof(int));

	return out;

}