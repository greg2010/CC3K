#include "ConcreteGoldStashGuarded.h"

void ConcreteGoldStashGuarded::freeGold(){
	free = true;
}

void ConcreteGoldStashGuarded::taken(Player &p){
	p.interact(*this);
}

bool const ConcreteGoldStashGuarded::isGuardianAlive(){
	return free;
}
