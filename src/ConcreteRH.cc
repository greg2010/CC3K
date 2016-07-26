#include "ConcreteRH.h"

const int restoreHealth = 10;

ConcreteRH::ConcreteRH(std::pair<int,int>coords):PotHP{coords}, value {restoreHealth}{}

int ConcreteRH::getHP(){
	return value;
}

SubjectType ConcreteRH::getType() {
    return SubjectType::RH;
}
