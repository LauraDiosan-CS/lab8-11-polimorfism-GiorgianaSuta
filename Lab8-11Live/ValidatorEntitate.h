#pragma once
#include <string>
#include "Entitate.h"

using namespace std;

class ValidatorEntitate {
public:
	ValidatorEntitate();
	~ValidatorEntitate();
	virtual void validate(Entitate* e);
};