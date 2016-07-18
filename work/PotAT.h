#ifndef _POTAT_
#define _POTAT_
#include "Potion.h"

class PotAt: public Potion{

	public:
		int getHP() override;
		int getDef() override;
};

#endif
