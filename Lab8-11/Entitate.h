#pragma once
#include <string>
using namespace std;

class Entitate {
protected:
	int cod;
	string nume;
	int pret;
	string data;
	int nr_exemplare;
public:
	Entitate();
	Entitate(int, string, int, string, int);
	Entitate(string, char);
	Entitate(const Entitate&);
	int getCod();
	string getNume();
	int getPret();
	string getData();
	int getNr();
	void setCod(int);
	void setNume(string);
	void setPret(int);
	void setData(string);
	void setNr(int);
	Entitate& operator =(const Entitate&);
	bool operator ==(const Entitate&);
	~Entitate();
	string toString();
	string toStringDelimiter(char);
};