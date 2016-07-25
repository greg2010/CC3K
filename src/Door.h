//
//  Door.h
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Door_h
#define Door_h

#include "Item.h"

class Door: public Item{
    
public:
    Door(std::pair<int,int>coords);
    SubjectType getType();
    bool walkable();
};

#endif /* Door_h */
