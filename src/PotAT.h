#ifndef _POTAT_
#define _POTAT_
#include "Potion.h"

class Player;

class PotAT: public Potion{

	public:
		void taken(Player &p) override;
		int getHP() override;
		int getDef() override;
};

#endif
