#ifndef A05_CONCRETEWEREWOLF_H
#define A05_CONCRETEWEREWOLF_H

#include "Enemy.h"

class ConcreteWerewolf : public Enemy {
public:
    ConcreteWerewolf(std::pair<int,int> coords);

    SubjectType getType() override;
};


#endif //A05_CONCRETEWEREWOLF_H
