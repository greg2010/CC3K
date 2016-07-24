#include "ConcreteOrc.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"

ConcreteOrc::ConcreteOrc(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteOrc::doInteract(ConcreteGoldStashNormal &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}

void ConcreteOrc::doInteract(ConcreteGoldStashGuarded &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}
