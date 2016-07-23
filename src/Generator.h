//
// Created by greg2010 on 19/07/16.
//

#ifndef A05_GENERATOR_H
#define A05_GENERATOR_H


#include <memory>
#include <string>
#include "Observer.h"
#include "Player.h"
#include "RandGen.h"

class Floor;

class Generator {
public:
    Generator(std::shared_ptr<Floor> floor, std::shared_ptr<Observer> display, std::shared_ptr<Player> player, unsigned int seed);
    void generate();
private:
    std::shared_ptr<Floor> FloorPtr;
    std::shared_ptr<Player> PlayerPtr;
    RandGen &RNG;

    int playerRoom;

    std::vector<std::vector<std::pair<int,int>>> rooms;

    void generatePotion(std::pair<int, int> coords);
    bool generateGold(std::pair<int, int> coords);
    void generateEnemy(std::pair<int, int> coords);
    std::pair<int, int> generateLocation(bool player, bool skip);
    //std::pair<int, int> generateLocation(std::pair<int, int> exclude);
};


#endif //A05_GENERATOR_H
