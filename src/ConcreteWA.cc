#include "ConcreteWA.h"

int ConcreteWA::getAtk(){
	if (decPot){
		return value + decPot->getAtk();
	} else {
		return value;
	}
}
