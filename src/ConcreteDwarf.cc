
#include "ConcreteDwarf.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"


const int defaultHP = 100;
const int defaultAtk = 20;
const int defaultDef = 30;

const int goldMultiplier = 2;

ConcreteDwarf::ConcreteDwarf(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteDwarf::doInteract(ConcreteGoldStashNormal &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}

void ConcreteDwarf::doInteract(ConcreteGoldStashGuarded &item) {
    this->addGold(item.getGoldValue() * goldMultiplier);
}
