#include "ConcreteWA.h"

const int woundAtk = -5;

ConcreteWA::ConcreteWA(std::pair<int,int>coords):PotAT{coords}, value{woundAtk}{}

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
