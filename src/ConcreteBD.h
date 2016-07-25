#ifndef _CONCRETEBD_
#define _CONCRETEBD_
#include "PotDE.h"

class ConcreteBD : public PotDE {
	int value;

	public:
		ConcreteBD(std::pair<int,int> coords);
		SubjectType getType() override;
		int getDef() override;
};

#endif
