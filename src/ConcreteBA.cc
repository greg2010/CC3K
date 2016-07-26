#include "ConcreteBA.h"

const int boostAtk = 5;

ConcreteBA::ConcreteBA(std::pair<int,int> coords):PotAT{coords}, value {boostAtk}{}

int ConcreteBA::getAtk(){
	if (decPot){
		return value + decPot->getAtk();
	} else {
		return value ;
	}
}

SubjectType ConcreteBA::getType() {
    return SubjectType::BA;
}
