//
//  Observer.hpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <stdio.h>
class Subject;
class Observer{
public:
    virtual void Notify(Subject* sub) = 0;
};
#endif /* Observer_hpp */
