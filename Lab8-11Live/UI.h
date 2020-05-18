#pragma once
#include <string>
#include "service.h"

using namespace std;

class UI
{
private:
	Service service;
	User u;
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
	void cautaProduse();
	void showMenu();
	void afisare();
	void cumpara();
	bool login();
	int logout();
	~UI();
};