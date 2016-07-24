#ifndef A05_CONCRETEMERCHANT_H
#define A05_CONCRETEMERCHANT_H

#include "Enemy.h"
#include "Subject.h"

class ConcreteMerchant : public Enemy {
public:
    ConcreteMerchant(std::pair<int,int> coords);
    bool isMoving() override;
    bool isHostile() override;

    void attackedBy(std::shared_ptr<Character> attacker) override;
    SubjectType getType() override;
private:
    static bool hostile;
};

#endif //A05_CONCRETEMERCHANT_H
