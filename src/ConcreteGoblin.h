//
// Created by greg2010 on 18/07/16.
//

#ifndef A05_CONCRETEGOBLIN_H
#define A05_CONCRETEGOBLIN_H

#include "Enemy.h"

class ConcreteGoblin : public Enemy {
public:
    ConcreteGoblin(std::pair<int,int> coords);

    virtual SubjectType getType();
};


#endif //A05_CONCRETEGOBLIN_H
