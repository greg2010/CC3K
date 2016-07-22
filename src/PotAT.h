#ifndef _POTAT_
#define _POTAT_
#include "Potion.h"

class Player;

class PotAT: public Potion{

	public:
		PotAT(std::pair<int,int> coords);
		void taken(Player &p) override;
		int getHP() override;
		int getDef() override;
};

#endif
