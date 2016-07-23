#include "ConcreteVampire.h"


const int defaultHP = 50;
const int defaultAtk = 25;
const int defaultDef = 25;


ConcreteVampire::ConcreteVampire(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

SubjectType ConcreteVampire::getType() {
    return SubjectType::Vampire;
}
