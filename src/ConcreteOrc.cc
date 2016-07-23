#include "ConcreteOrc.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"


const int defaultHP = 180;
const int defaultAtk = 30;
const int defaultDef = 25;

const double goldMultiplier = 1/2;

ConcreteOrc::ConcreteOrc(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteOrc::doInteract(ConcreteGoldStashNormal &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}

void ConcreteOrc::doInteract(ConcreteGoldStashGuarded &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}
