#include "Enemy.h"

Enemy::Enemy(int HP, int atk, int def, std::pair<int,int> coords) : Character{HP, atk, def, coords} {

}


bool Enemy::isHostile() { return true; }

bool Enemy::isMoving() { return true; }



