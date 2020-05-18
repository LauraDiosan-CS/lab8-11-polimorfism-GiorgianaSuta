#pragma once
#include "RepoFile.h"
#include "RepoUser.h"

class Service {
private:
	RepoFile* rep;
	RepoUser repoUser;
	
public:
	Service();
	Service(RepoFile* rep, RepoUser repoUser);
	~Service();

	void setRepo(RepoFile* newrep);
	void setRepoUser(RepoUser newrepoUser);

	Entitate* getElementAtPosition(int pos);
	vector<Entitate*> getAll();
	void addProdus(Entitate* p);
	void updateProdus(Entitate* pVechi, Entitate* pNou);
	void removeProdus(Entitate* p);
	int getSizeProdus();
	vector<Entitate*> cautaProdusbyName(string);
	vector<Entitate*> cautaProdusbyData(string);
	//int findProdus(Entitate* p);

	vector<User> getUsers();
	void addUser(User& u);
	void updateUser(User& uv, User& un);
	int removeUser(User& u);
	int getSizeUser();
	int findUser(User& u);

	bool login(string, string);
	int logout(string, string);

	int cumpara(string, int, int& pretTotal);
	
};