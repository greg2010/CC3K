#include "ConcreteOrc.h"

ConcreteOrc::ConcreteOrc(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteOrc::doInteract(std::shared_ptr<ConcreteGoldStashNormal> item) {
    this->addGold(item->getValue() * goldMultiplier);
}

void ConcreteOrc::doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item) {
    this->addGold(item->getValue() * goldMultiplier);
}