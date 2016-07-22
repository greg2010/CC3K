#ifndef _CGSN_
#define _CGSN_
#include "GoldStash.h"

class Player;

class ConcreteGoldStashNormal: public GoldStash{
	
	int value;

	public:
		void taken(Player & p) override;
		int getGoldValue();
};

#endif
