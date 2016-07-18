#ifndef _CONCRETEWA_
#define _CONCRETEWA_
#include "PotAT.h"

class ConcreteWA: public PotAT{
	int value;
	public:
		int getAtk() override;
};

#endif
