#include "ConcreteTroll.h"

const int defaultHP = 120;
const int defaultAtk = 25;
const int defaultDef = 15;

ConcreteTroll::ConcreteTroll(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

SubjectType ConcreteTroll::getType() {
    return SubjectType::Troll;
}
