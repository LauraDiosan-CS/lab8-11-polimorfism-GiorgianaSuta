#include "ValidatorEntitate.h"
#include "ValidatorException.h"

ValidatorEntitate::ValidatorEntitate()
{
}

ValidatorEntitate::~ValidatorEntitate()
{
}

void ValidatorEntitate::validate(Entitate* e)
{

	if (e->getPret() <= 0)
	{
		throw ValidationException("Pretul trebuie sa fie pozitiv!");
	}
	
	if (e->getNr() < 0)
	{
		throw ValidationException("Nr de exemplare trebuie sa fie numar pozitiv!");
	}

}
