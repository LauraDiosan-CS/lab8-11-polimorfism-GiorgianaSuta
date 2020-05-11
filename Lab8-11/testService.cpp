#include "TestService.h"
#include "service.h"
#include <assert.h>

void testService() {
	
	RepoFile* rep = new RepoFileTXT("testService.txt");
	RepoUser repoUser;
	Service service(rep, repoUser);
	assert(service.getAll().size() == 0);
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	Produs* p2 = new Produs("e21", "mancare", 50, "21/02/2019", "21/02/2021", 100);
	service.addProdus(a1);
	service.addProdus(p2);
	assert(service.getSizeProdus() == 2);
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



}