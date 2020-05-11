#pragma once
#include "Entitate.h"

#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Entitate*> produse;
	string fileName;
	
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Entitate*> getAll();
	int getSize();
	Entitate* getProdus(int pos);
	void addProdus(Entitate* p);
	void updateProdus(Entitate* pVechi, Entitate* pNou);
	void deleteProdus(Entitate* p);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


