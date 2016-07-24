
#include "ConcreteDwarf.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"

ConcreteDwarf::ConcreteDwarf(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteDwarf::doInteract(ConcreteGoldStashNormal &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}

void ConcreteDwarf::doInteract(ConcreteGoldStashGuarded &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}
