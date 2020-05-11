#include "service.h"

Service::Service()
{
	
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

	this->rep->addProdus(p);
	
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


void Service::removeUser(User& u)
{
	this->repoUser.removeUser(u);
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

