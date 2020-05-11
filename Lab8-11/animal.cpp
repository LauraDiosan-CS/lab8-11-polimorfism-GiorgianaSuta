#include <iostream>
#include <string.h>
#include "utils.h"
#include "animal.h"

using namespace std;

Animal::Animal() : Entitate(){
	this->varsta = 0;
}

Animal::Animal(string cod, string nume, int pret, string data, int varsta, int nr):Entitate(cod, nume, pret, data, nr){
	this->varsta = varsta;
}
Animal::Animal(const Animal& a):Entitate(a)
{
	this->varsta = a.varsta;
}

int Animal::getVarsta() {
	return this->varsta;
}

Entitate* Animal::clone() {
	return new Animal(this->cod, this->nume, this->pret, this->data, this->varsta, this->nr_exemplare);
}
void Animal::setVarsta(int v)
{
	this->varsta = v;
}

Animal& Animal::operator=(const Animal& a)
{
	this->cod = a.cod;
	this->nume = a.nume;
	this->pret = a.pret;
	this->data = a.data;
	this->varsta = a.varsta;
	this->nr_exemplare = a.nr_exemplare;
	
	return *this;
}
bool Animal::operator== (const Animal& a)
{
	if (cod == a.cod)
		return true;
	return false;
}


string Animal::toString(string delim) {
	return "AA" + delim + this->cod +delim + this->nume + convertIntToString(pret) + delim + data + convertIntToString(varsta) + delim + convertIntToString(nr_exemplare);
}



Animal::~Animal() {
	
}

