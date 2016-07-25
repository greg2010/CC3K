//
//  Wall.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Wall.h"

Wall::Wall(std::pair<int,int>coords):Item{coords}{}

SubjectType Wall::getType() {
    return SubjectType::Wall;
}

bool Wall::walkable() {
    return false;
}