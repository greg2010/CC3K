#include "ConcreteGoldStashNormal.h"
#include "Player.h"

void ConcreteGoldStashNormal::taken(Player &p){
	p.interact(*this);
}

int ConcreteGoldStashNormal::getGoldValue(){
	return value;
}
