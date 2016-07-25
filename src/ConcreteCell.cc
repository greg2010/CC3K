#include "ConcreteCell.h"

ConcreteCell::ConcreteCell(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteCell::getType() {
    return SubjectType::Cell;
}

bool ConcreteCell::walkable() {
    return true;
}
