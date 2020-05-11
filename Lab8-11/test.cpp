#include <assert.h>
#include "test.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "animal.h"
#include "produs.h"



void TestRepoFile::testGetSize()
{
	
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addProdus(new Produs());
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	
	RepoFile* repoFile = new RepoFileTXT();
	Animal* a1 = new Animal("as3","caine", 100, "23/02/2020", 1, 20);
	Produs* p2 = new Produs("e21","mancare", 50,"21/02/2019","21/02/2021",100);
	repoFile->addProdus(a1);
	repoFile->addProdus(p2);
	vector<Entitate*> produse = repoFile->getAll();
	assert(*produse[0] == *a1->clone());
	assert(*produse[1] == *p2->clone());
}

void TestRepoFile::testGetProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	repoFile->addProdus(a1);
	assert(*repoFile->getProdus(0) == *a1->clone());
	assert(*repoFile->getProdus(-1) == *(new Produs()));
	assert(*repoFile->getProdus(1) == *(new Produs()));
}

void TestRepoFile::testAddProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	repoFile->addProdus(a1);
	assert(*repoFile->getProdus(0) == *a1->clone());
}

void TestRepoFile::testUpdateProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	repoFile->addProdus(a1);
	Animal* a2 = new Animal("as2", "pisica", 100, "23/02/2020", 1, 20);
	Animal* a3 = new Animal("as6", "cangur", 100, "23/02/2020", 1, 20);

	repoFile->updateProdus(a3, a2);
	assert(*repoFile->getProdus(0) == *a1);
	repoFile->updateProdus(a1, a2);
	assert(*repoFile->getProdus(0) == *a2);
}

void TestRepoFile::testDeleteProdus()
{
	RepoFile* repoFile = new RepoFileTXT();
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	repoFile->addProdus(a1);
	Animal* a2 = new Animal("as2", "pisica", 100, "23/02/2020", 1, 20);
	repoFile->deleteProdus(a2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getProdus(0) == *a1);
	repoFile->deleteProdus(a1);
	assert(repoFile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size());
	assert(*repoFile->getProdus(0) == *this->produseIn[0]);
	assert(*repoFile->getProdus(1) == *this->produseIn[1]);
}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size());
	assert(*repoFile->getProdus(0) == *this->produseIn[0]);
	assert(*repoFile->getProdus(1) == *this->produseIn[1]);
}

void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	Animal* newa = new Animal("as10", "iepure", 200, "23/02/2020", 1, 20);
	repoFile->addProdus(newa);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size() + 1);
	vector<Entitate*> produse = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*produse[i] == *this->produseIn[i]);
	}
	assert(*produse[produse.size() - 1] == *newa);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	Animal* newa = new Animal("as10", "iepure", 200, "23/02/2020", 1, 20);
	repoFile->addProdus(newa);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->produseIn.size() + 1);
	vector<Entitate*> produse = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*produse[i] == *this->produseIn[i]);
	}
	assert(*produse[produse.size() - 1] == *newa);
}

TestRepoFile::TestRepoFile()
{
	Animal* a1 = new Animal("as3", "caine", 100, "23/02/2020", 1, 20);
	Produs* p2 = new Produs("e21", "mancare", 50, "21/02/2019", "21/02/2021", 100);
	this->produseIn.push_back(a1);
	this->produseIn.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetProdus();
	this->testAddProdus();
	this->testUpdateProdus();
	this->testDeleteProdus();
	this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();
}