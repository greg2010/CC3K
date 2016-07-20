#include "ConcretePhoenix.h"

ConcretePhoenix::ConcretePhoenix(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }