#ifndef _POTHP_
#define _POTHP_
#include "Potion.h"

class Player;

class PotHP: public Potion{

	public:
		PotHP(std::pair<int,int> coords);
		void taken(Player &p) override;
		int getAtk() override;
		int getDef() override;

};

#endif
