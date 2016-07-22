
#include "ConcreteDwarf.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"

ConcreteDwarf::ConcreteDwarf(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteDwarf::doInteract(std::shared_ptr<ConcreteGoldStashNormal> item) {
    this->addGold(item->getValue() * goldMultiplier);
}

void ConcreteDwarf::doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item) {
    this->addGold(item->getValue() * goldMultiplier);
}
