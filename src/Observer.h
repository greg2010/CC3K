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
#include <memory>

class Subject;
class Observer{
public:
    virtual void notify(std::shared_ptr<Subject> sub) = 0;
    virtual ~Observer();
};
#endif /* Observer_hpp */
