#include "ConcreteVampire.h"

ConcreteVampire::ConcreteVampire(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }