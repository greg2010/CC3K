//
//  ConcreteWallV.h
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Wall_v
#define Wall_v

#include "Item.h"

class ConcreteWallV: public Item{
public:
    ConcreteWallV(std::pair<int,int>coords);
    SubjectType getType();
    bool walkable();
};

#endif /* Wall_v */
