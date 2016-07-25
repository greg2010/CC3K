//
//  ConcreteWall.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "ConcreteWallH.h"

ConcreteWallH::ConcreteWallH(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteWallH::getType() {
    return SubjectType::WallH;
}

bool ConcreteWallH::walkable() {
    return false;
}
