#pragma once
#include "ValidatorEntitate.h"

class ValidatorAnimal : public ValidatorEntitate {
public:
	ValidatorAnimal();
	~ValidatorAnimal();
	void validate(Entitate* e);
};