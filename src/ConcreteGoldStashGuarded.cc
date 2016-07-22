#include "ConcreteGoldStashGuarded.h"
#include "Player.h"

ConcreteGoldStashGuarded::ConcreteGoldStashGuarded(std::pair<int,int> coords, int value): GoldStash{coords}, value{value}{}

void ConcreteGoldStashGuarded::freeGold(){
	free = true;
}

void ConcreteGoldStashGuarded::taken(Player &p){
	p.interact(*this);
}

bool const ConcreteGoldStashGuarded::isGuardianAlive(){
	return free;
}

int ConcreteGoldStashGuarded::getGoldValue(){
	return value;
}
