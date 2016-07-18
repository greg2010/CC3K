#ifndef _CONCRETERH_
#define _CONCRETERH_
#include "PotHP.h"

class ConcreteRH: public PotHP{
	int value;
	public:
		int getHP() override;
};

#endif
