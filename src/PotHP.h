#ifndef _POTHP_
#define _POTHP_
#include "Potion.h"

class Player;

class PotHP: public Potion{

	public:
		void taken(Player &p) override;
		int getAtk() override;
		int getDef() override;

};

#endif
