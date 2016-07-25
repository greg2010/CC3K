#ifndef _CONCRETEWD_
#define _CONCRETEWD_
#include "PotDE.h"

class ConcreteWD : public PotDE{
	int value;

	public:
		ConcreteWD(std::pair<int,int> coords);
		SubjectType getType() override;
		int getDef() override;
};

#endif
