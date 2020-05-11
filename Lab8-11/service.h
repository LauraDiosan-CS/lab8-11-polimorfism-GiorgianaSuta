#pragma once
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "RepoUser.h"
#include "animal.h"
#include "produs.h"

#include "user.h"

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

	vector<Entitate*> getAll();
	void addProdus(Entitate* p);
	void updateProdus(Entitate* pVechi, Entitate* pNou);
	void removeProdus(Entitate* p);
	int getSizeProdus();
	//int findProdus(Entitate* p);

	vector<User> getUsers();
	void addUser(User& u);
	void updateUser(User& uv, User& un);
	void removeUser(User& u);
	int getSizeUser();
	int findUser(User& u);

	bool login(string, string);
	


	
	
};