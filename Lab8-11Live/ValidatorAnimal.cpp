#include "ValidatorAnimal.h"
#include "animal.h"
#include "ValidatorException.h"

ValidatorAnimal::ValidatorAnimal()
{
}
ValidatorAnimal::~ValidatorAnimal()
{
}

void ValidatorAnimal::validate(Entitate* a)
{
	Animal* aa = (Animal*)a;
	
	
	if (aa->getPret() <= 0)
	{
		throw ValidationException("Pretul trebuie sa fie pozitiv!");
	}
	
	if (aa->getNr() < 0)
	{
		throw ValidationException("Nr de exemplare trebuie sa fie numar pozitiv!");
	}
	if (aa->getVarsta() < 0)
	{
		throw ValidationException("Varsta trebuie sa fie pozitiva!");
	}

}