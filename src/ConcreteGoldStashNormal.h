#ifndef _CGSN_
#define _CGSN_
#include "GoldStash.h"

class ConcreteGoldStashNormal: public GoldStash{
	int value;

	public:
		int getGoldValue();
};

#endif
