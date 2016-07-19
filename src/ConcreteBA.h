#ifndef _CONCRETEBA_
#define _CONCRETEBA_
#include "PotAT.h"

class ConcreteBA: public PotAT{
	int value;
	public:
		int getAtk() override;
};

#endif
