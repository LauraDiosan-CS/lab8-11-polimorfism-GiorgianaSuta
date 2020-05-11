#include "UI.h"
#include "animal.h"
#include "produs.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include <iostream>
using namespace std;



UI::UI()
{
}

UI::UI(Service& s)
{
	this->service = s;
}

UI::~UI()
{
}

void UI::AdaugareUser()
{
	RepoUser r;
	User u1("Giorgi", "12345");
	User u2("Diana7", "0000");
	r.add(u1);
	r.add(u2);
	service.setRepoUser(r);
}

void UI::AlegereFisier()
{
	string opt;
	int i = 0;
	
	RepoFile* r = new RepoFileTXT("produse.txt");
	RepoFile* r1 = new RepoFileCSV("produse.csv");
	while (i == 0)
	{
		cout << "Dati structura fisierului txt sau csv: ";
		cin >> opt;
		if (opt == "txt")
		{
			this->service.setRepo(r);
			r->loadFromFile();
			i = 1;
		}
		if (opt == "csv")
		{
			this->service.setRepo(r1);
			r1->loadFromFile();
			i = 1;
		}
		if (i == 0)
		{
			cout << "Dati o optiuna alcatuita din txt sau csv !" << endl;
		}
	}
}

void UI::showMenu()
{
	cout << "Bine ati venit! Va rugam sa va logati!" << endl;
	bool gata = false;
	bool ok = login();
	if (ok == true)
	{
		AlegereFisier();
		while (!gata) {
			cout << "1. Adaugare animal" << endl;
			cout << "2. Adaugare produs" << endl;
			cout << "3. Stergere animal" << endl;
			cout << "4. Stergere produs" << endl;
			cout << "5. Modifica animal " << endl;
			cout << "6. Modifica produs" << endl;
			cout << "7. Afisare produse" << endl;
			cout << "0. Exit!" << endl;
			


			int opt;
			cout << "Dati optiunea:";
			cin >> opt;
			switch (opt) {
			case 1: {addAnimal(); break; }
			case 2: {addProdus(); break; }
			case 3: {deleteAnimal(); break; }
			case 4: {deleteProdus(); break; }
			case 5: {updateAnimal(); break; }
			case 6: {updateProdus(); break; }
			case 7: {afisare(); break; }
			case 0: {
				
				gata = true;
			}
			}
		}
	}
	else {
		cout << "Autentificarea a esuat!" << endl;
	}
}

void UI::addAnimal()
{
	string cod, nume, data;
	int pret, varsta, nr;
	cout << "Dati un cod pentru animal: ";
	cin >> cod;
	cout << "Dati un nume pentru animal: ";
	cin >> nume;
	cout << "Dati un pret pentru animal: ";
	cin >> pret;
	cout << "Dati o data pentru animal: ";
	cin >> data;
	cout << "Dati o varsta pentru animal: ";
	cin >> varsta;
	cout << "Dati numarul de exemplare al animalului: ";
	cin >> nr;
	Animal* a = new Animal(cod, nume, pret, data, varsta, nr);
	e.exceptionAnimal(a);
	this->service.addProdus(a);
	
}

void UI::addProdus()
{

	string cod, nume, data, dataexp;
	int pret, nr;
	cout << "Dati un cod pentru produs: ";
	cin >> cod;
	cout << "Dati un nume pentru produs: ";
	cin >> nume;
	cout << "Dati un pret pentru produs: ";
	cin >> pret;
	cout << "Dati o data pentru produs: ";
	cin >> data;
	cout << "Dati o data de expirare pentru produs: ";
	cin >> dataexp;
	cout << "Dati numarul de exemplare al produsului: ";
	cin >> nr;
	Produs* p = new Produs(cod, nume, pret, data, dataexp, nr);
	e.exceptionProdus(p);
	this->service.addProdus(p);
	

	
}

void UI::deleteAnimal()
{
	string cod, nume = " "; 
	string data = " ";
	int pret = 0;
	int varsta = 0;
	int nr= 0;
	cout << "Dati un cod pentru animalul sters: ";
	cin >> cod;
	Animal* a = new Animal(cod, nume, pret, data, varsta, nr);
	this->service.removeProdus(a);
}

void UI::deleteProdus()
{
	string cod;
	string nume = " ";
	string data= "";
	string dataexp = "";
	int pret = 0;
	int nr = 0;
	cout << "Dati un cod pentru produsul sters: ";
	cin >> cod;
	
	Produs* p = new Produs(cod, nume, pret, data, dataexp, nr);
	this->service.removeProdus(p);
}

void UI::updateAnimal()
{
	string cod, nume, data;
	int pret,varsta, nr;
	cout << "Dati un cod pentru animalul modificat: ";
	cin >> cod;
	cout << "Dati un nume pentru animalul modificat: ";
	cin >> nume;
	cout << "Dati un pret pentru animalul modificat: ";
	cin >> pret;
	cout << "Dati o data pentru animalul modificat: ";
	cin >> data;
	cout << "Dati o varsta pentru animalul modificat: ";
	cin >> varsta;
	cout << "Dati numarul de exemplare al animalului modificat: ";
	cin >> nr;
	Animal* aNou = new Animal(cod, nume, pret, data, varsta, nr);
	Animal* a = new Animal(cod, "", 0, "", varsta, 0);
	this->service.updateProdus(a, aNou);
}

void UI::updateProdus()
{
	string cod, nume, data, dataexp;
	int pret, nr;
	cout << "Dati un cod pentru produsul modificat: ";
	cin >> cod;
	cout << "Dati un nume pentru produsul modificat: ";
	cin >> nume;
	cout << "Dati un pret pentru produsul modificat: ";
	cin >> pret;
	cout << "Dati o data pentru produsul modificat: ";
	cin >> data;
	cout << "Dati o data de expirare al produsului modificat: ";
	cin >> dataexp;
	cout << "Dati numarul de exemplare al produsul modificat: ";
	cin >> nr;
	Produs* p = new Produs(cod, nume, pret, data, dataexp, nr);
	Produs* p1 = new Produs(cod, "", 0, "", "", 0);
	this->service.updateProdus(p1, p);
}



void UI::afisare()
{
	for (int i = 0; i < this->service.getSizeProdus(); i++)
	{
		cout << endl;
		cout << this->service.getAll()[i]->toString(" ");
		cout << endl;

	}
}

bool UI::login()
{
	string nume, parola;
	cout << "Dati numele contului: ";
	cin >> nume;
	cout << "Dati parola contului: ";
	cin >> parola;
	u.setUserName(nume);
	u.setPassword(parola);
	return this->service.login(nume, parola);
}

