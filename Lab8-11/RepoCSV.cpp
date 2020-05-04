#include "RepoCSV.h"
#include <fstream>
#include "animal.h"
#include "produs.h"

RepositoryFileCSV::RepositoryFileCSV() : RepoFile()
{
}

RepositoryFileCSV::RepositoryFileCSV(string fileName) : RepoFile(fileName)
{
}

RepositoryFileCSV::~RepositoryFileCSV()
{
}

void RepositoryFileCSV::loadFromFile()
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
				int cod = stoi(linie.substr(0, pos));
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
				int nr = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				Animal* a= new Animal(cod, nume, pret, data,varsta, nr );
				this->elem.push_back(a);
			}
			else if (linie.substr(0, 2) == "AP")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				int cod = stoi(linie.substr(0, pos));
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
				int nr = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				Produs* p = new Produs(cod, nume, pret, data, data_exp, nr);
				this->elem.push_back(p);
			}
		}
		f.close();
	}
}

void RepositoryFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Entitate* e : this->elem)
		{
			f << e->toString(",") << endl;
		}
	}
}
