#include "TestRepo.h"
#include <assert.h>

void TestRepo::runCSVTests()
{
	const char* fileNameAnimal = "animal.csv";
	Animal a(1, "caine", 100, "12.02.2020", 1, 5);
	RepositoryFile<Animal>* repoAnimal = new RepositoryFileCSV<Animal>(fileNameAnimal);
	((RepositoryFileCSV<Animal>*)repoAnimal)->loadFromFile();
	assert(repoAnimal->size() == 1);
	repoAnimal->add(a);
	assert(repoAnimal->size() == 2);
	repoAnimal->remove(a);
	assert(repoAnimal->size() == 1);
	assert(repoAnimal->find(a) == -1);

}