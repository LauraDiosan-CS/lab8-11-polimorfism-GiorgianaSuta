
#include "produs.h"
#include "utils.h"

using namespace std;

Produs::Produs() : Entitate()
{
	
}
Produs::Produs(string cod, string nume,int pret,string data, string data_exp, int nr):
	Entitate(cod, nume, pret, data, nr){
	this->data_exp = data_exp;
}

Produs::Produs(const Produs& p ):Entitate(p)
{
	this->data_exp = p.data_exp;
}

string Produs::getDataExp() {
	return this->data_exp;
}
void Produs::setDataExp(string d)
{
	this->data_exp = d;
}

Entitate* Produs::clone() {
	return new Produs(this->cod, this->nume, this->pret, this->data, this->data_exp, this->nr_exemplare);
}
Produs& Produs :: operator = (const Produs& p)
{
	this->cod = p.cod;
	this->nume = p.nume;
	this->pret = p.pret;
	this->data = p.data;
	this->data_exp = p.data_exp;
	this->nr_exemplare = p.nr_exemplare;

	return *this;
}
bool Produs:: operator == (const Produs& p)
{
	if (cod == p.cod)
		return true;
	return false;
}


string Produs::toString(string delim)
{
	return "AP" + delim + this->cod + delim + this->nume + delim + convertIntToString(this->pret) + delim + this->data + delim + this->data_exp + delim + convertIntToString(this->nr_exemplare);
}

Produs::~Produs() {
	
}
