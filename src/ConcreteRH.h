#ifndef _CONCRETERH_
#define _CONCRETERH_
#include "PotHP.h"

class ConcreteRH: public PotHP{
	int value;
	public:
		ConcreteRH(std::pair<int,int>coords);
		int getHP() override;
};

#endif
