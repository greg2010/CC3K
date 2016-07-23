#include "ConcreteGoblin.h"


const int defaultHP = 70;
const int defaultAtk = 5;
const int defaultDef = 10;


ConcreteGoblin::ConcreteGoblin(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

SubjectType ConcreteGoblin::getType() {
    return SubjectType::Goblin;
}
