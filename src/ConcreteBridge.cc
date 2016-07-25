//
//  ConcreteBridge.cpp
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "ConcreteBridge.h"

ConcreteBridge::ConcreteBridge(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteBridge::getType() {
    return SubjectType::Bridge;
}

bool ConcreteBridge::walkable() {
    return true;
}
