#ifndef _CONCRETEBA_
#define _CONCRETEBA_
#include "PotAT.h"

class ConcreteBA: public PotAT {
	int value;
	public:
		ConcreteBA(std::pair<int,int>coords);
		int getAtk() override;
};

#endif
