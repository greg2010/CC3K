//
// Created by greg2010 on 18/07/16.
//

#ifndef A05_CONCRETETROLL_H
#define A05_CONCRETETROLL_H

#include "Enemy.h"

const int defaultHP = 120;
const int defaultAtk = 25;
const int defaultDef = 15;

class ConcreteTroll : public Enemy {

    ConcreteTroll(std::pair<int,int> coords);

};

#endif //A05_CONCRETETROLL_H
