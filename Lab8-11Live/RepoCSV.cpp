#include "RepoCSV.h"
#include <fstream>
#include "animal.h"
#include "produs.h"


RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile() 
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "AA")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string cod= linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int pret = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int varsta = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_exemplare = stoi(linie.substr(0, pos));
			

				Animal* aa = new Animal (cod, nume, pret,data, varsta,nr_exemplare);
				this->produse.push_back(aa);
			}
			else if (linie.substr(0, 2) == "AP")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string cod = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int pret = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data_exp = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_exemplare = stoi(linie.substr(0, pos));

				Produs* ap = new Produs(cod, nume, pret,data, data_exp, nr_exemplare);
				this->produse.push_back(ap);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Entitate* elem : this->produse)
		{
			f << elem->toString(",") << endl;
		}
	}
}