#include "RepoUser.h"
#include <vector>
using namespace std;

RepoUser::RepoUser() {}

RepoUser::~RepoUser()
{}
vector<User> RepoUser::getAll()
{
	return this->users;
}

int RepoUser::getSize()
{
	return this->users.size();
}

User RepoUser::getUser(int pos)
{
	if (pos >= 0 && pos < users.size())
	{
		return this->users[pos];
	}
	
}

void RepoUser::add(User& u)
{
	int aux = 0;
	for (size_t i = 0; i < this->users.size(); i++)
	{
		if (this->users[i].getUserName() != u.getUserName())
		{
			this->users.push_back(u);
			aux = 1;
		}
	}
	if (this->users.size() == 0)
	{
		this->users.push_back(u);
	}
	
}

void RepoUser::update(User& uVechi, User& uNou)
{
	vector<User>::iterator it;
	it = find(users.begin(), users.end(), uVechi);
	if (it != users.end())
		(*it) = uNou;
}
int RepoUser::findUser(User& u)
{
	auto it = find(this->users.begin(), this->users.end(), u);
	if (it != this->users.end())
		return distance(users.begin(), it);
	return -1;
}
int RepoUser::removeUser(User& u)
{
	auto it = find(this->users.begin(), this->users.end(), u);
	if (it != this->users.end()){
		users.erase(it, users.end());
		return 0;
	}
	return -1;
}
