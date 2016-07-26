#ifndef _POTDE_
#define _POTDE_
#include "Potion.h"

class Player;

class PotDE: public Potion{
	public:
		PotDE(std::pair<int,int> coords);
		void doTaken(Player &p) override;
		int getHP() override;
		int getAtk() override;
};

#endif
