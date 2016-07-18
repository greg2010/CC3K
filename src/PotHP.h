#ifndef _POTHP_
#define _POTHP_
#include "Potion.h"

class PotHP: public Potion{

	public:
		int getAtk() override;
		int getDef() override;

};

#endif
