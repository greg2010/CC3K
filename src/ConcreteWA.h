#ifndef _CONCRETEWA_
#define _CONCRETEWA_
#include "PotAT.h"

class ConcreteWA: public PotAT{
	int value;
	public:
		ConcreteWA(std::pair<int,int>coords);
		int getAtk() override;
};

#endif
