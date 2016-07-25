//
//  Door.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Door.h"

Door::Door(std::pair<int,int>coords):Item{coords}{}

SubjectType Door::getType() {
    return SubjectType::Door;
}

bool Door::walkable() {
    return true;
}