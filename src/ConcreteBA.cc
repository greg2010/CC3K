#include "ConcreteBA.h"

int ConcreteBA::getAtk(){
	if (decPot){
		return value + decPot->getAtk();
	} else {
		return value ;
	}
}
