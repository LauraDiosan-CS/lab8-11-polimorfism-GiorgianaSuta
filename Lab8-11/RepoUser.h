#pragma once
#include "user.h"
#include <vector>

using namespace std;

class RepoUser {
private:
	vector<User> users;
	
public:
	RepoUser();
	
	~RepoUser();
	

	vector<User> getAll();
	int getSize();
	User getUser(int pos);
	void add(User& u);
	void update(User& uVechi, User& uNou);
	int removeUser(User& u);
	int findUser(User& u);

	
};