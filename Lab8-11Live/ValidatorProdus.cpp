#include "ValidatorProdus.h"
#include "produs.h"
#include "ValidatorException.h"

ValidatorProdus::ValidatorProdus() {}
ValidatorProdus::~ValidatorProdus()
{
}
void ValidatorProdus::validate(Entitate* e)
{
	ValidatorEntitate::validate(e);
	
	
}
