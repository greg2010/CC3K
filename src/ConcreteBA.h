#ifndef _CONCRETEBA_
#define _CONCRETEBA_
#include "PotAT.h"

class ConcreteBA: public PotAT {
	int value;
	public:
		ConcreteBA(std::pair<int,int>coords);
		SubjectType getType() override;
		int getAtk() override;
};

#endif
