#include "test.h"
#include <assert.h>
/*
void Test::testAnimal() {
	Animal a(1, "caine", 100, "23/02/2020", 1, 20);
	assert(a.getCod() == 1);
	assert(a.getNr() == 20);
	a.setNume("pisica");
	assert(a.getNume() == "pisica");
}

void Test::testProdus() {
	Produs p(1, "lesa", 30, "22/01/2020", "23/01/2030", 100);
	assert(p.getCod() == 1);
	p.setNume("mancare");
	assert(p.getNume() == "mancare");
}
void Test::testUser() {
	User user("Giorgi27", "12345687");
	assert(user.getUserName() == "Giorgi27");
	assert(user.getPassword() == "12345687");
	user.setPassword("1234");
	assert(user.getPassword() == "1234");
}
void Test::testRepoAnimal() {
	IRepository<Animal> repoAnimal;
	Animal a(1, "caine", 100, "23/02/2020", 1, 20);
	repoAnimal.add(a);
	assert(repoAnimal.size() == 1);
	Animal a1(1, "pisica", 90, "12/02/2020", 2, 2);
	repoAnimal.update(a, a1);
	int i = repoAnimal.find(a);
	assert(repoAnimal.getAll()[i].getNr() == 2);
	repoAnimal.remove(a1);
	assert(repoAnimal.size() == 0);
}
void Test::testRepoProdus() {
	IRepository<Produs> repoProdus;
	Produs p(1, "mancare", 20, "12/02/2020", "12/02/2022", 12);
	repoProdus.add(p);
	assert(repoProdus.size() == 1);
	Produs p1(1, "jucarie", 20, "12/02/2020", "12/02/2030", 100);
	repoProdus.update(p, p1);
	int i = repoProdus.find(p);
	assert(repoProdus.getAll()[i].getNr() == 100);
	repoProdus.remove(p1);
	assert(repoProdus.size() == 0);

	
}
void Test::testRepoCSV() {
	RepositoryFile<Animal>* repoAnimal = new RepositoryFileCSV<Animal>("testAnimal.csv");
	((RepositoryFileCSV<Animal>*)repoAnimal)->loadFromFile();
	assert(repoAnimal->size() == 0);
	Animal a(1, "caine", 100, "23/02/2020", 1, 20);
	repoAnimal->add(a);
	repoAnimal->saveToFile();
	assert(repoAnimal->size() == 1);
	repoAnimal->remove(a);
	repoAnimal->saveToFile();
	assert(repoAnimal->size() == 0);
	assert(repoAnimal->find(a) == -1);
	
	RepositoryFile<Produs>* repoProdus = new RepositoryFileCSV<Produs>("testProdus.csv");
	((RepositoryFileCSV<Produs>*) repoProdus)->loadFromFile();
	assert(repoProdus->size() == 0);
	Produs p(1, "mancare", 20, "12/02/2020", "12/02/2022", 12);
	repoProdus->add(p);
	repoProdus->saveToFile();
	assert(repoProdus->size() == 1);
	repoProdus->remove(p);
	repoProdus->saveToFile();
	assert(repoProdus->size() == 0);
	assert(repoProdus->find(p) == -1);

	*/

void Test::testLive() {
	RepoFile* repo = new RepositoryFileCSV("fisier-112-1.cs");
	repo->loadFromFile();
	Entitate* a1 = new Animal(1, "papagal", 100, "01.04.2020", 2, 5);
	Entitate* a2 = new Produs(1, "mancare_pesti", 30, "11.12.2019", "01.01.2022", 12);
	Entitate* a3 = new Animal(2, "hamster", 60, "03.05.2020", 1, 3);
	Entitate* a4 = new Animal(3, "canar", 70, "07.03.2020", 3, 1);
	assert(repo->size() == 2);
	assert(*(repo->findElem(0)) == *a2);
	assert(*(repo->findElem(1)) == *a1);
	repo->add(a3);
	assert(repo->size() == 3);
	assert(*(repo->findElem(0)) == *a3);
	assert(*(repo->findElem(1)) == *a2);
	assert(*(repo->findElem(2)) == *a1);
	repo->add(a4);
	assert(repo->size() == 3);
	assert(*(repo->findElem(0)) == *a3);
	assert(*(repo->findElem(1)) == *a4);
	assert(*(repo->findElem(2)) == *a1);


}
/*
void Test::testRepoTXT() {
	RepositoryFile<Animal>* repoAnimal = new RepositoryFileTXT<Animal>("testAnimal.txt");
	((RepositoryFileTXT<Animal>*)repoAnimal)->loadFromFile();
	assert(repoAnimal->size() == 0);
	Animal a(1, "caine", 100, "23/02/2020", 1, 20);
	repoAnimal->add(a);
	
	assert(repoAnimal->size() == 1);
	repoAnimal->remove(a);
	
	assert(repoAnimal->size() == 0);
	assert(repoAnimal->find(a) == -1);

	RepositoryFile<Produs>* repoProdus = new RepositoryFileTXT<Produs>("testProdus.txt");
	((RepositoryFileTXT<Produs>*) repoProdus)->loadFromFile();
	assert(repoProdus->size() == 0);
	Produs p(1, "mancare", 20, "12/02/2020", "12/02/2022", 12);
	repoProdus->add(p);
	
	assert(repoProdus->size() == 1);
	repoProdus->remove(p);
	
	assert(repoProdus->size() == 0);
	assert(repoProdus->find(p) == -1);
}
*/
void Test::testRun() {
	//testAnimal();
	//testProdus();
	//testUser();
	//testRepoAnimal();
	//testRepoCSV();
	//testRepoTXT();
	//testRepoProdus();
	testLive();
}