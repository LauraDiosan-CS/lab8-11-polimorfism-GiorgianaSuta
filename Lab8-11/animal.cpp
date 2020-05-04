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

Animal::Animal(string str, char delimiter)
{
	vector<string> tokens = splitLine(str, delimiter);
	cod = stoi(tokens[0]);
	nume = tokens[1];
	pret = stoi(tokens[2]);
	data = tokens[3];
	varsta = stoi(tokens[4]);
	nr_exemplare = stoi(tokens[5]);
}
string Animal::toString() {
	return to_string(cod) + "-" + nume + '-' + to_string(pret) + '-' + data + '-'+to_string(varsta) +'-'+ to_string(nr_exemplare);
}

string Animal::toStringDelimiter(char delim)
{
	return to_string(cod) + delim + nume + delim + to_string(pret) + delim + data + delim + to_string(varsta) + delim +  to_string(nr_exemplare);
}

Animal::~Animal() {
	varsta = -1;
}

