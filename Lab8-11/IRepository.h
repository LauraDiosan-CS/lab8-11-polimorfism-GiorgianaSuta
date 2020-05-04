#pragma once
#include <vector>
#include "Entitate.h"

using namespace std;


class RepoFile {
protected:
	vector<Entitate*> elem;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	void add(Entitate* e);
	void update(Entitate*, Entitate*);
	void remove(Entitate*);
	int size();
	Entitate* findElem(int);
	vector<Entitate*> getAll();
	void setFileName(string fileName);
	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
	~RepoFile();
};

