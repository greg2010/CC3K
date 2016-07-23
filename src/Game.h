//
//  Game.h
//  cc3k
//
//  Created by YoY on 2016-07-17.
//  Copyright © 2016 YoY. All rights reserved.
//


#ifndef Game_h
#define Game_h

#include <memory>
#include <string>

class Player;
class Floor;
class Subject;
class Game {
    std::shared_ptr<Player> generatePlayer();
    int currFloor;
    std::shared_ptr<Floor> floor;
    std::shared_ptr<Player> player;
    std::string playerType;
public:
    Game();
    ~Game();
    std::shared_ptr<Floor> getCurrentFloor();
    bool movePlayer (std::string dir);
    void generateNextFloor();
};

#endif /* Game_h */
