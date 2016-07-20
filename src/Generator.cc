//
// Created by greg2010 on 19/07/16.
//

#include "Generator.h"

Generator::Generator(std::shared_ptr<Floor> floor,
                     std::shared_ptr<Observer> display,
                     std::shared_ptr<Player> player, unsigned int seed) : FloorPtr{floor},
                                                                          PlayerPtr{player},
                                                                          RNG{RandGen::getInstance(seed)} { }

void Generator::generate() {
    std::pair<int,int> playerCoords = generateLocation();
    PlayerPtr->assignCoords(playerCoords);
    std::pair<int,int> stairwayCoords = generateLocation(playerCoords);
    // put stairway
    for (int i = 0; i < 10; ++i) {
        generatePotion(generateLocation());
    }
    for (int i = 0; i < 10; ++i) {
        generateGold(generateLocation());
    }
    for (int i = 0; i < 20; ++i) {
        generateEnemy(generateLocation());
    }
}

std::pair<int, int> Generator::generateLocation() {
    // do magic
}





