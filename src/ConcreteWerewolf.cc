#include "ConcreteWerewolf.h"

ConcreteWerewolf::ConcreteWerewolf(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }