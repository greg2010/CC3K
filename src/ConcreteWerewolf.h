#ifndef A05_CONCRETEWEREWOLF_H
#define A05_CONCRETEWEREWOLF_H

#include "Enemy.h"

class ConcreteWerewolf : public Enemy {
public:
    ConcreteWerewolf(std::pair<int,int> coords);

    virtual SubjectType getType();
};


#endif //A05_CONCRETEWEREWOLF_H
