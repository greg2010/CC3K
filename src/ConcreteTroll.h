//
// Created by greg2010 on 18/07/16.
//

#ifndef A05_CONCRETETROLL_H
#define A05_CONCRETETROLL_H

#include "Enemy.h"

class ConcreteTroll : public Enemy {
public:
    ConcreteTroll(std::pair<int,int> coords);

    virtual SubjectType getType();
};

#endif //A05_CONCRETETROLL_H
