#pragma once
#include "IRepository.h"
#include <fstream>
using namespace std;

 class RepositoryFileCSV :
	public RepoFile
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(string fileName);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCSV();
};

