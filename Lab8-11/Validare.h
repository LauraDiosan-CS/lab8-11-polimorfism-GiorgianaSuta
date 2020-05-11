#pragma once
#include "animal.h"
#include "produs.h"
#include "Entitate.h"
#include "MyInputStringException.h"
#include "MyNrException.h"
#include <exception>
using namespace std;

class Validare {

public:
	Validare() {};
	void exceptionAnimal(Entitate* a1)
	{
		Animal* a = (Animal*)a1;
		if (a->getNr() < 0)
			throw MyNumberException("Numarul trebuie sa fie pozitiv!");
		if(a->getPret() <= 0 )
			throw MyNumberException("Pretul trebuie sa fie pozitiv!");
		if(a->getVarsta() <=0)
			throw MyNumberException("Numarul trebuie sa fie pozitiv!");
	}
	void exceptionProdus(Entitate* p1)
	{
		Produs* p = (Produs*)p1;
		if (p->getNr() < 0)
			throw MyNumberException("Numarul trebuie sa fie pozitiv!");
		if (p->getPret() <= 0)
			throw MyNumberException("Pretul trebuie sa fie pozitiv!");
	}
	~Validare() {};
};