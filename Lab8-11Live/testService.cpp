#include "TestService.h"
#include "service.h"
#include "animal.h"
#include "produs.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include <iostream>
#include <assert.h>
using namespace std;
void testService() {
	RepoFile* rep = new RepoFileTXT("testLive12.txt");
	RepoUser repoUser;
	Service service;
	service.setRepo(rep);
	rep->loadFromFile();
	
	Animal* a1 = new Animal("554", "papagal", 100, "01.04.2020", 2, 5);
	Produs* a2 = new Produs("554", "mancare_pesti", 30, "11.12.2019", "01.01.2022", 12);
	Animal* a3 = new Animal("555", "papagal", 60, "03.05.2020", 1, 3);
	Animal* a4 = new Animal("554", "papagal", 70, "07.03.2020", 3, 3);
	Produs* a5 = new Produs("554", "mancare_pesti", 30, "11.12.2019", "01.01.2022", 20);
	service.addProdus(a1);
	service.addProdus(a2);
	service.addProdus(a3);
	assert(service.getAll().size() == 3);
	assert(*service.getElementAtPosition(0) == *a1);
	assert(*service.getElementAtPosition(1) == *a2);
	assert(*service.getElementAtPosition(2) == *a3);

	service.addProdus(a4);
	assert(service.getAll().size() == 3);
	assert((*service.getElementAtPosition(0)).getCod() == (*a1).getCod());
	assert((*service.getElementAtPosition(0)).getNume() == (*a1).getNume());
	assert((*service.getElementAtPosition(0)).getNr() == 8);
	assert(*service.getElementAtPosition(1) == *a2);
	assert(*service.getElementAtPosition(2) == *a3);
	service.addProdus(a5);
	assert(service.getSizeProdus() == 3);
	assert((*service.getElementAtPosition(0)).getCod() == (*a1).getCod());
	assert((*service.getElementAtPosition(0)).getNume() == (*a1).getNume());
	assert((*service.getElementAtPosition(0)).getNr() == 8);
	assert((*service.getElementAtPosition(1)).getCod() == (*a2).getCod());
	assert((*service.getElementAtPosition(0)).getNume() == (*a2).getNume());
	assert((*service.getElementAtPosition(1)).getNr() == 32);
	assert((*service.getElementAtPosition(1)) == (*a3));

	
	
	/*
	RepoFile* rep = new RepoFileTXT("testService.txt");
	RepoUser repoUser;
	Service service(rep, repoUser);
	assert(service.getAll().size() == 0);
	Animal* a1 = new Animal("as3", "caine", 100, "21/02/2019", 1, 20);
	Produs* p2 = new Produs("e21", "mancare", 50, "21/02/2019", "21/02/2021", 100);
	service.addProdus(a1);
	service.addProdus(p2);
	assert(service.getSizeProdus() == 2);
	
	//test cauta

	vector<Entitate*> rez = service.cautaProdusbyName("caine");
	assert(rez.size() == 1);
	
	vector<Entitate*> rez2 = service.cautaProdusbyData("21/02/2019");
	assert(rez2.size() == 2);
	
	//test cumpara
	int pret = 0;
	int rezultat = service.cumpara("as3", 4, pret);
	assert(rezultat == 0);
	assert(pret == 400);
	int pret2 = 0;
	int rezultat1 = service.cumpara("e21", 200, pret2);
	assert(rezultat1 == -1);

	
	Animal* a2 = new Animal("as3", "pisica", 200, "23/02/2020", 2, 20);
	assert(*rep->getProdus(0) == *a1);
	service.updateProdus(a1, a2);
	assert(*rep->getProdus(0) == *a2);
	service.removeProdus(p2);
	assert(service.getSizeProdus() == 1);
	


	User u4("Paul", "123456");
	assert(service.getSizeUser() == 0);
	service.addUser(u4);
	bool ok = service.login("Paul", "123456");
	assert(ok == true);

	assert(service.getSizeUser() == 1);
	service.removeUser(u4);
	assert(service.getSizeUser() == 0);

	User u5("User1", "0000");
	service.addUser(u5);
	bool ok1 = service.login("User1", "0000");
	int aux = service.logout("User1", "0000");
	assert(aux == 0);

	*/
}