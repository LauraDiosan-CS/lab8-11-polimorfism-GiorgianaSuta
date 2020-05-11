#pragma once
#include <string>
#include "service.h"
#include "Validare.h"
using namespace std;

class UI
{
private:
	Service service;
	User u;
	Validare e;
	
public:
	UI();
	UI(Service& s);

	void AdaugareUser();
	void AlegereFisier();
	void addProdus();
	void addAnimal();
	void deleteAnimal();
	void deleteProdus();
	void updateAnimal();
	void updateProdus();

	void showMenu();
	void afisare();
	bool login();
	~UI();
};