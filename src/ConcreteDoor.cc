//
//  ConcreteDoor.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "ConcreteDoor.h"

ConcreteDoor::ConcreteDoor(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteDoor::getType() {
    return SubjectType::Door;
}

bool ConcreteDoor::walkable() {
    return true;
}
