#include <iostream>
#include <string.h>
#include "utils.h"
#include "animal.h"

using namespace std;

Animal::Animal() {
	this->varsta = 0;
}

Animal::Animal(int cod, string nume, int pret, string data, int varsta, int nr):Entitate(cod, nume, pret, data, nr){
	this->varsta = varsta;
}
Animal::Animal(const Animal& a):Entitate(a)
{
	this->varsta = a.varsta;
}

int Animal::getVarsta() {
	return this->varsta;
}

void Animal::setVarsta(int v)
{
	varsta = v;
}

Animal& Animal::operator=(const Animal& a)
{
	Entitate::operator= (a);
	this->setVarsta(a.varsta);
	return *this;
}
bool Animal::operator== (const Animal& a)
{
	if (cod == a.cod)
		return true;
	return false;
}



string Animal::toString(string delim)
{
	return "AA" + delim + convertIntToString(this->cod) + delim + nume + delim + convertIntToString(pret) + delim + data + delim + convertIntToString(varsta) + delim +  convertIntToString(nr_exemplare);
}
Entitate* Animal::clone()
{
	return new Animal(this->cod, this->nume, this->pret, this->data,this->varsta, this->nr_exemplare);
}
Animal::~Animal() {
	varsta = -1;
}

