//
//  ConcreteWall.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "ConcreteWall.h"

ConcreteWall::ConcreteWall(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteWall::getType() {
    return SubjectType::Wall;
}

bool ConcreteWall::walkable() {
    return false;
}
