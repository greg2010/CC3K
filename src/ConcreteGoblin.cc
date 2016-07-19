#include "ConcreteGoblin.h"

ConcreteGoblin::ConcreteGoblin(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }