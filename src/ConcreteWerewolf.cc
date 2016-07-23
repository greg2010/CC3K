#include "ConcreteWerewolf.h"
#include "TextDisplay.h"


const int defaultHP = 120;
const int defaultAtk = 30;
const int defaultDef = 5;

ConcreteWerewolf::ConcreteWerewolf(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

SubjectType ConcreteWerewolf::getType() {
    return SubjectType::Werewolf;
}
