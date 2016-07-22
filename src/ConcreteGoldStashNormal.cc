#include "ConcreteGoldStashNormal.h"
#include "Player.h"

ConcreteGoldStashNormal::ConcreteGoldStashNormal(std::pair<int,int>coords, int value): GoldStash{coords}, value{value}{};

void ConcreteGoldStashNormal::taken(Player &p){
	p.interact(*this);
}

int ConcreteGoldStashNormal::getGoldValue(){
	return value;
}
