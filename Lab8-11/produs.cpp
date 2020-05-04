#include <iostream>
#include <string.h>
#include "produs.h"
#include "utils.h"
#include <vector>
using namespace std;

Produs::Produs()
{
	this->data_exp = "";
}
Produs::Produs(int cod, string nume,int pret,string data, string data_exp, int nr):
	Entitate(cod, nume, pret, data, nr){
	this->data_exp = data_exp;
}
Produs::Produs(string str, char delim)
{
	vector<string>  tokens = splitLine(str, delim);
	cod = stoi(tokens[0]);
	nume = tokens[1];
	pret = stoi(tokens[2]);
	data = tokens[3];
	data_exp = tokens[4];
	nr_exemplare = stoi(tokens[5]);

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

Produs& Produs :: operator = (const Produs& p)
{
	this->data_exp = p.data_exp;
	Entitate::operator = (p);
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
	return "AP"+ delim + to_string(cod) + delim + nume + delim + to_string(pret) + delim + data + delim + data_exp + delim + to_string(nr_exemplare);
}
Entitate* Produs::clone()
{
	return new Produs(this->cod, this->nume, this->pret, this->data, this->data_exp, this->nr_exemplare);
}
Produs::~Produs() {
	this->data_exp = "";
}
