#include "testEntitate.h"
#include "animal.h"
#include "produs.h"
#include <assert.h>

void testEntitate() {
	Animal a1("as3", "caine", 100, "23/02/2020", 1, 20);
	Produs p2("e21", "mancare", 50, "21/02/2019", "21/02/2021", 100);
	assert(a1.getCod() == "as3");
	assert(p2.getCod() == "e21");
	assert(a1.getNr() == 20);
	assert(p2.getNr() == 100);
	Animal* aClone = (Animal*)a1.clone();
	assert(a1 == *aClone);
	assert(&a1 != aClone);
	a1.setNume("pisica");
	assert(a1.getNume() == "pisica");
	assert(p2.toString(" ") == "AP e21 mancare 50 21/02/2019 21/02/2021 100");
	assert(p2.toString(",") == "AP,e21,mancare,50,21/02/2019,21/02/2021,100");
}