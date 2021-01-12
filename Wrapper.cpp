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

ostream& operator<<(ostream& iesire, Wrapper& w)
{
	iesire << "Produs: \n" << "ID: " << w.produs.getIdProdus() << "\n" << "NUME: " << w.produs.getNumeProdus() << "\n" << "PRET: " << w.produs.getPretProdus() << endl;

	return iesire;
}
