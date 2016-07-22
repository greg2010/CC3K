#ifndef A05_ENEMY_H
#define A05_ENEMY_H


#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int HP, int atk, int def, std::pair<int,int> coords);
    void doTurn();

    virtual bool isHostile();
    virtual bool isMoving();
};


#endif //A05_ENEMY_H
