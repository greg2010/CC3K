#ifndef _POTDE_
#define _POTDE_
#include "Potion.h"

class Player;

class PotDE: public Potion{
	public:
		void taken(Player &p) override;
		int getHP() override;
		int getAtk() override;
};

#endif
