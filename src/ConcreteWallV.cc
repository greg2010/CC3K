//
//  ConcreteWallV.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "ConcreteWallV.h"

ConcreteWallV::ConcreteWallV(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteWallV::getType() {
    return SubjectType::WallV;
}

bool ConcreteWallV::walkable() {
    return false;
}
