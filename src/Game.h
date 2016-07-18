//
//  Game.h
//  cc3k
//
//  Created by YoY on 2016-07-17.
//  Copyright © 2016 YoY. All rights reserved.
//


#ifndef Game_h
#define Game_h
#include <iostream>

class Player;
class Floor;
class Subject;
class Game {
    Player * generatePlayer();
    int currFloor;
    Floor* floor;
    Player* player;
public:
    Game();
    ~Game();
    Floor * getCurrentFloor();
    bool movePlayer (std::string dir);
    void generateNextFloor();
};

#endif /* Game_h */
