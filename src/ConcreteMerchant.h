#ifndef A05_CONCRETEMERCHANT_H
#define A05_CONCRETEMERCHANT_H

#include "Enemy.h"

class ConcreteMerchant : public Enemy {
    ConcreteMerchant(std::pair<int,int> coords);
    virtual bool isMoving();
    virtual bool isHostile();

    virtual void attackedBy(std::shared_ptr<Character> attacker);

private:
    static bool hostile;
};

#endif //A05_CONCRETEMERCHANT_H
