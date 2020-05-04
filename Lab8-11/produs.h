#pragma once
#include "Entitate.h"


using namespace std;

class Produs:public Entitate {
private:
	string data_exp;
	
public:
	Produs();
	Produs(int, string,int,  string, string, int);
	Produs(const Produs&);
	Produs(string, char);
	string getDataExp();
	void setDataExp(string);
	
	string toString(string);
	Produs& operator= (const Produs&);
	bool operator == (const Produs&);
	Entitate* clone();
	~Produs();
	
};