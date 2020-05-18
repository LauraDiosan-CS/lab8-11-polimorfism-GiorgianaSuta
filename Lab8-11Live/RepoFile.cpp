#include "RepoFile.h"
#include <typeinfo>
#include "animal.h"
#include "produs.h"


RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Entitate*> RepoFile::getAll()
{
	return this->produse;
}

int RepoFile::getSize()
{
	return this->produse.size();
}

Entitate* RepoFile::getProdus(int pos) 
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->produse[pos]->clone();
	}
	
}

void RepoFile::addProdus(Entitate* p) 
{
	this->produse.push_back(p->clone());
	this->saveToFile();
}
int RepoFile::findProdus(Entitate* p)
{
	for (int i = 0; i < this->produse.size(); i++)
	{
		if (this->produse[i]->getCod() == p->getCod())
		{
			return i;
		}
	}
	return -1;
}
void RepoFile::updateProdus(Entitate* pVechi, Entitate* pNou) 
{
	
	for (int i = 0; i < this->produse.size(); i++)
	{
		if (this->getProdus(i)->getCod() == pVechi->getCod())
		{
			delete this->produse[i];
			this->produse[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteProdus(Entitate* p) 
{
	for (int i = 0; i < this->produse.size(); i++)
	{
		
		if (this->produse[i]->getCod() == p->getCod())
		{
			delete this->produse[i];
			this->produse.erase(this->produse.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->produse[i];
	}
	this->produse.clear();
}