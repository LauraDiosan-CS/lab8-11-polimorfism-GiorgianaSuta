#pragma once
#include "Entitate.h"
using namespace std;

class Animal:public Entitate {
private:
	
	int varsta;
	
public:
	Animal();
	Animal(string, string,int, string, int, int);
	Animal(const Animal&);
	~Animal();

	Entitate* clone();

	int getVarsta();
	void setVarsta(int);
	Animal& operator =(const Animal&);
	bool operator ==(const Animal&);
	string toString(string delim);
	
	
};