#ifndef A05_CONCRETEPHOENIX_H
#define A05_CONCRETEPHOENIX_H


#include "Enemy.h"
#include "Subject.h"

class ConcretePhoenix : public Enemy {
public:
    ConcretePhoenix(std::pair<int,int> coords);
    SubjectType getType() override;

};


#endif //A05_CONCRETEPHOENIX_H
