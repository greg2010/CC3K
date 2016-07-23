#include "ConcreteDragon.h"

ConcreteDragon::ConcreteDragon(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

bool ConcreteDragon::isMoving() {
    return false;
}

SubjectType ConcreteDragon::getType() {
    return SubjectType::Dragon;
}
