#pragma once
#include <string>
using namespace std;

class Entitate {
protected:
	string cod;
	string nume;
	int pret;
	string data;
	int nr_exemplare;
public:
	Entitate();
	Entitate(string, string, int, string, int);
	Entitate(const Entitate&);
	~Entitate();

	virtual Entitate* clone();

	string getCod();
	string getNume();
	int getPret();
	string getData();
	int getNr();
	void setCod(string);
	void setNume(string);
	void setPret(int);
	void setData(string);
	void setNr(int);
	Entitate& operator =(const Entitate&);
	bool operator ==(const Entitate&);
	
	virtual string toString(string delim);
};