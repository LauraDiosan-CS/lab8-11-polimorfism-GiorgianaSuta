#include "IRepository.h"

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
	return this->elem;
}

int RepoFile::size()
{
	return this->elem.size();
}

Entitate* RepoFile::findElem(int pos)
{
	if (pos >= 0 && pos < this->size())
	{
		return this->elem[pos]->clone();
	}
	return new Entitate();
}

void RepoFile::add(Entitate* e)
{
	this->elem.push_back(e->clone());
	this->saveToFile();
}

void RepoFile::update(Entitate* pVechi, Entitate* pNou)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (*(this->findElem(i)) == *pVechi)
		{
			delete this->elem[i];
			this->elem[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::remove(Entitate* p)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (**(this->elem.begin() + i) == *p)
		{
			delete this->elem[i];
			
			this->elem.erase(this->elem.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->size(); i++)
	{
		delete this->elem[i];
	}
	this->elem.clear();
}
