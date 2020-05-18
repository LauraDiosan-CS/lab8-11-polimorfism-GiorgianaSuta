#include "UI.h"
#include "animal.h"
#include "produs.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "ValidatorException.h"
#include <Windows.h>
#include "RepoException.h"
#include <iostream>
#include "utils.h"
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
void UI::cautaProduse()
{
	string op;
	cout << "Dupa ce doriti sa cautati? Nume/data introducerii in magazin " << endl;
	cin >> op;
	
	if (op == "nume")
	{
		string nume;
		cout << "Dati numele dupa care doriti sa faceti cautarea!" << endl;
		cin >> nume;
		vector<Entitate*> rez = service.cautaProdusbyName(nume);
		for (Entitate* e : rez)
			cout << e->toString(" ") << endl;
	}
	if (op == "data")
	{
		string data;
		cout << "Dati data dupa care doriti sa faceti cautarea!" << endl;
		cin >> data;
		vector<Entitate*> rez2 = service.cautaProdusbyData(data);
		for (Entitate* e : rez2)
			cout << e->toString(" ") << endl;
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
			HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(color, 15);
			cout << endl;
			cout << "1. Adaugare animal" << endl;
			cout << "2. Adaugare produs" << endl;
			cout << "3. Stergere animal" << endl;
			cout << "4. Stergere produs" << endl;
			cout << "5. Modifica animal " << endl;
			cout << "6. Modifica produs" << endl;
			cout << "7. Afisare produse" << endl;
			cout << "8. Cauta produse dupa nume/data introducerii in magazin!" << endl;
			cout << "9. Cumpara produse!" << endl;
			cout << "0. Logout!" << endl;
			
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
			case 8: {cautaProduse(); break; }
			case 9: {cumpara(); break; }
			case 0: 
			{
				int rez = logout();
				if (rez == 0)
				{
					cout << "Ati reusit! Logout!";
				}
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
	try {
		this->service.addProdus(a);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
	
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
	try {
		this->service.addProdus(p);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
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
	try {
		this->service.removeProdus(a);
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}

void UI::deleteProdus()
{
	string cod;
	string nume = " ";
	string data = "";
	string dataexp = "";
	int pret = 0;
	int nr = 0;
	cout << "Dati un cod pentru produsul sters: ";
	cin >> cod;
	Produs* p = new Produs(cod, nume, pret, data, dataexp, nr);
	try {
		this->service.removeProdus(p);
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
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
	try {
		this->service.updateProdus(a,aNou);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
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
	try {
		this->service.updateProdus(p1, p);
	}
	catch (ValidationException& e) {
		cout << e.what() << endl;
	}
	catch (RepoException& e) {
		cout << e.what() << endl;
	}
}



void UI::afisare()
{
	for (int i = 0; i < this->service.getSizeProdus(); i++)
	{
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		if (this->service.getAll()[i]->getNr() == 0)
		{
			SetConsoleTextAttribute(color, 12);
			cout << this->service.getAll()[i]->toString(" ") << endl;

		}
		else
		{
			SetConsoleTextAttribute(color, 15);
			cout << this->service.getAll()[i]->toString(" ") << endl;

		}
		
	}
}
void UI::cumpara()
{
	string cod;
	cout << "Dati codul produsului:" << endl;
	cin >> cod;
	int cantitate;
	int pretTotal;
	cout << " Dati cantitatea de produse pe care le doriti: " << endl;
	cin >> cantitate;
	int status = this->service.cumpara(cod, cantitate, pretTotal);
	if (status == 0)
	{
		cout << "Produsul " + cod + "a fost cumparat! Costul total este " + convertIntToString(pretTotal) + " lei" << endl;
		afisare();
		return;
	}
	if (status == -1)
	{
		cout << " Nu sunt suficiente exemplare pe stoc!";
		return;
	}
	cout << "Nu exista niciun produs cu codul  " + cod + "!" << endl;
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

int UI::logout()
{
	return this->service.logout(u.getUserName(), u.getPassword());
}

