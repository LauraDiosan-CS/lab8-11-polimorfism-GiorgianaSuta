#include "Entitate.h"
#include "utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Entitate::Entitate() {
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
	this->data = "";
	this->nr_exemplare = 0;
}

Entitate::Entitate(int cod, string nume, int pret, string data, int nr)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
	this->data = data;
	this->nr_exemplare = nr;
}

Entitate::Entitate(const Entitate& e)
{
	this->cod = e.cod;
	this->nume = e.nume;
	this->pret = e.pret;
	this->data = e.data;
	this->nr_exemplare = e.nr_exemplare;
}
int Entitate::getCod() {
	return this->cod;

}
string Entitate::getNume() {
	return this->nume;
}
int Entitate::getPret() {
	return this->pret;
}
string Entitate::getData() {
	return this->data;
}

int Entitate::getNr() {
	return this->nr_exemplare;
}
void Entitate::setCod(int c)
{
	this->cod = c;
}
void Entitate::setNume(string n)
{
	this->nume = n;

}
void Entitate::setPret(int p)
{
	this->pret = p;
}
void Entitate::setData(string d)
{
	this->data = d;
}

void Entitate::setNr(int nr)
{
	this->nr_exemplare = nr;
}
bool Entitate::operator==(const Entitate& e)
{
	return e.cod == cod;
}
Entitate& Entitate::operator=(const Entitate& e)
{
	this->setCod(e.cod);
	this->setNume(e.nume);
	this->setPret(e.pret);
	this->setData(e.data);
	this->setNr(e.nr_exemplare);

	return *this;
}


string Entitate::toString(string delim)
{
	return convertIntToString(cod) + delim + nume + delim + convertIntToString(pret) + delim + data + delim + convertIntToString(nr_exemplare);
}
Entitate* Entitate::clone()
{
	return new Entitate(this->cod, this->nume, this->pret, this->data, this->nr_exemplare);
}
Entitate::~Entitate()
{}