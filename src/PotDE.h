#ifndef _POTDE_
#define _POTDE_
#include "Potion.h"

class PotDE: public Potion{
	public:
		int getHP() override;
		int getAtk() override;
};

#endif
