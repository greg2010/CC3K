#include "ConcreteGoldStashGuarded.h"

void ConcreteGoldStashGuarded::freeGold(){
	free = true;
}

bool const ConcreteGoldStashGuarded::isGuardianAlive(){
	return free;
}
