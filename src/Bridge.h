//
//  Bridge.hpp
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Bridge_h
#define Bridge_h

#include "Item.h"

class Bridge: public Item{
    
public:
    Bridge(std::pair<int,int>coords);
    SubjectType getType();
    bool walkable();
};

#endif /* Bridge_h */
