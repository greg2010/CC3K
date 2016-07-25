#ifndef _CONCRETEWA_
#define _CONCRETEWA_
#include "PotAT.h"

class ConcreteWA: public PotAT{
	int value;
	public:
		ConcreteWA(std::pair<int,int>coords);
		SubjectType getType() override;
		int getAtk() override;
};

#endif
