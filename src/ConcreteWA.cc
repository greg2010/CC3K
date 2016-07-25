#include "ConcreteWA.h"

ConcreteWA::ConcreteWA(std::pair<int,int>coords):PotAT{coords}{}

int ConcreteWA::getAtk(){
	if (decPot){
		return value + decPot->getAtk();
	} else {
		return value;
	}
}

SubjectType ConcreteWA::getType() {
    return SubjectType::WA;
}
