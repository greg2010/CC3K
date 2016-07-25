//
//  Wall.h
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Wall_h
#define Wall_h

#include "Item.h"

class Wall: public Item{
    
public:
    Wall(std::pair<int,int>coords);
    SubjectType getType();
    bool walkable();
};

#endif /* Wall_h */
