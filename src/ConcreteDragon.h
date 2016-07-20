//
// Created by greg2010 on 18/07/16.
//

#ifndef A05_CONCRETEDRAGON_H
#define A05_CONCRETEDRAGON_H

#include "Enemy.h"

const int defaultHP = 150;
const int defaultAtk = 20;
const int defaultDef = 20;

class ConcreteDragon : public Enemy {

    ConcreteDragon(std::pair<int,int> coords);

    virtual bool isMoving();

};


#endif //A05_CONCRETEDRAGON_H
