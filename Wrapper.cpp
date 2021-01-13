#include "Wrapper.h"

Wrapper::Wrapper(Produs produs, int cantitateProdus)
{
	this->produs = produs;
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

ostream& operator<<(ostream& iesire, Wrapper& w)
{
	iesire << " \nProdus:" << "ID: " << w.produs.getIdProdus() << "\n" << "NUME: " << w.produs.getNumeProdus() 
		<< "\n" << "PRET: " << w.produs.getPretProdus() << "\nCANTITATE: " << w.getCantitateProdus()<<endl;

	return iesire;
}
