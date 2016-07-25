//
//  Bridge.cpp
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Bridge.h"

Bridge::Bridge(std::pair<int,int>coords):Item{coords}{}

SubjectType Bridge::getType() {
    return SubjectType::Door;
}

bool Bridge::walkable() {
    return true;
}