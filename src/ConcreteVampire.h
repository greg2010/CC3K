#ifndef A05_CONCRETEVAMPIRE_H
#define A05_CONCRETEVAMPIRE_H

#include "Enemy.h"

class ConcreteVampire : public Enemy {
public:
    ConcreteVampire(std::pair<int,int> coords);

    SubjectType getType() override;

};


#endif //A05_CONCRETEVAMPIRE_H
