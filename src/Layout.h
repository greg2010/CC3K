//
//  Layout.h
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Layout_h
#define Layout_h

#include <stdio.h>
#include <vector>

class Layout {
public:
    const virtual std::vector< std::pair<int, int> > & getLocation();
    
};

#endif /* Layout_h */
