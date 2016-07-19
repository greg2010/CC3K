#ifndef A05_CONCRETEMERCHANT_H
#define A05_CONCRETEMERCHANT_H

#include "Enemy.h"

const int defaultHP = 30;
const int defaultAtk = 70;
const int defaultDef = 5;

class ConcreteMerchant : public Enemy {
    ConcreteMerchant(std::pair<int,int> coords);
    virtual bool isMoving();
    virtual bool isHostile();

    virtual void attackedBy(std::shared_ptr<Character> attacker);

private:
    static bool hostile;
};

#endif //A05_CONCRETEMERCHANT_H
