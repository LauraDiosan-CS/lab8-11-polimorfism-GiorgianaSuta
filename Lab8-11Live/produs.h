
#pragma once
#include "Entitate.h"


using namespace std;

class Produs:public Entitate {
private:
	string data_exp;
	
public:
	Produs();
	Produs(string, string,int,  string, string, int);
	Produs(const Produs&);
	~Produs();
	
	Entitate* clone();

	string getDataExp();
	void setDataExp(string);
	string toString(string delim);
	Produs& operator= (const Produs&);
	bool operator == (const Produs&);
	
	
};