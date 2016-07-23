#include "ConcreteHuman.h"


const int defaultHP = 140;
const int defaultAtk = 20;
const int defaultDef = 20;

ConcreteHuman::ConcreteHuman(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }
