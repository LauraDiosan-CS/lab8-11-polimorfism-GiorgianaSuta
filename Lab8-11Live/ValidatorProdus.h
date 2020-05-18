#pragma once
#include "ValidatorEntitate.h"

class ValidatorProdus : public ValidatorEntitate {
public:
	ValidatorProdus();
	~ValidatorProdus();
	void validate(Entitate* e);
};