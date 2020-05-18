#include "service.h"
#include <algorithm>
#include "animal.h"
#include "produs.h"


using namespace std;


Service::Service()
{
	this->rep = NULL;
}

Service::Service(RepoFile* repo, RepoUser repouser)
{
	this->rep = repo;
	this->repoUser = repouser;
}

Service::~Service()
{
}

vector<Entitate*> Service::getAll()
{
	return this->rep->getAll();
}

vector<User> Service::getUsers()
{
	return this->repoUser.getAll();
}

void Service::setRepo(RepoFile* newrepo)
{
	this->rep = newrepo;
}

void Service::setRepoUser(RepoUser repouser)
{
	this->repoUser = repouser;
}

void Service::addProdus(Entitate* p)

{
	vector<Entitate*> all = this->getAll();
	if (all.size() == 0)
	{
		this->rep->addProdus(p);
	}
	else {
		for (int i = 0; i < this->rep->getSize(); i++)
		{
			if (this->rep->getAll()[i]->getCod() == p->getCod() && this->rep->getAll()[i]->getNume() == p->getNume())
			{
				int nr_ex = p->getNr();
				rep->getAll()[i]->setNr(rep->getAll()[i]->getNr() + nr_ex);
			}
			else {
				this->rep->addProdus(p);
			}
		}
	}
	
}
int Service::getSizeProdus()
{
	return this->rep->getSize();
}
void Service::updateProdus(Entitate* vechim, Entitate* noum)

{
	this->rep->updateProdus(vechim, noum);
}

void Service::removeProdus(Entitate* p)

{
	this->rep->deleteProdus(p);
}

void Service::addUser(User& u)
{
	this->repoUser.add(u);
}



int Service::getSizeUser()
{
	return this->repoUser.getSize();
}



void Service::updateUser(User& uvechi, User& unou)
{
	this->repoUser.update(uvechi, unou);
}


int Service::removeUser(User& u)
{
	return this->repoUser.removeUser(u);
}



int Service::findUser(User& u)
{
	return this->repoUser.findUser(u);
}

bool Service::login(string nume, string parola)
{
	User u(nume, parola);

	return this->repoUser.findUser(u) != -1;
}
int Service::logout(string nume, string parola)
{
	User u(nume, parola);
	return this->repoUser.removeUser(u);

}
vector<Entitate*> Service::cautaProdusbyName(string nume)
{
	vector<Entitate*> all = rep->getAll();
	vector<Entitate*> rez;
	for (Entitate* crt : all)
	{
		if (crt->getNume() == nume)
		{
			rez.push_back(crt);
		}
	}
	return rez;
}
vector<Entitate*> Service::cautaProdusbyData(string data)
{
	vector<Entitate*> all = rep->getAll();
	vector<Entitate*> rez;
	for (Entitate* crt : all)
	{
		if (crt->getData() == data)
		{
			rez.push_back(crt);
		}
	}
	return rez;
}
int Service::cumpara(string cod, int cantitate, int& pretTotal)
{
	pretTotal = 0;
	vector<Entitate*> produse = this->rep->getAll();
	for (Entitate* p : produse)
	{
		if (p->getCod() == cod)
		{
			if (p->getNr() >= cantitate)
			{
				pretTotal = p->getPret() * cantitate;
				p->setNr(p->getNr() - cantitate);
				rep->saveToFile();
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
	return -2;
}
Entitate* Service::getElementAtPosition(int pos)
{
	return this->rep->getProdus(pos);
}


