#include "ConcretePhoenix.h"


const int defaultHP = 50;
const int defaultAtk = 35;
const int defaultDef = 20;


ConcretePhoenix::ConcretePhoenix(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }
