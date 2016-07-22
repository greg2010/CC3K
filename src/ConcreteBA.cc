#include "ConcreteBA.h"

ConcreteBA::ConcreteBA(std::pair<int,int> coords):PotAT{coords}{}

int ConcreteBA::getAtk(){
	if (decPot){
		return value + decPot->getAtk();
	} else {
		return value ;
	}
}
