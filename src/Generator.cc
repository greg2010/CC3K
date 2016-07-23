//
// Created by greg2010 on 19/07/16.
//

#include "Generator.h"
#include "ConcreteChamber.h"

Generator::Generator(std::shared_ptr<Floor> floor,
                     std::shared_ptr<Observer> display,
                     std::shared_ptr<Player> player, unsigned int seed) : FloorPtr{floor},
                                                                          PlayerPtr{player},
                                                                          RNG{RandGen::getInstance(seed)}{
									  
										  std::vector<ConcreteChamber> chambers = FloorPtr->getChambers();
										  
										  for (auto ch : chambers){
											  rooms.push_back(ch.getCellCoords());
										  }
										
									  }

void Generator::generate() {
    std::pair<int,int> playerCoords = generateLocation(true, false);
    PlayerPtr->assignCoords(playerCoords);
    std::pair<int,int> stairwayCoords = generateLocation(false, true);
    // put stairway
    for (int i = 0; i < 10; ++i) {
        generatePotion(generateLocation(false,false));
    }
    for (int i = 0; i < 10; ++i) {
        generateGold(generateLocation(false,false));
    }
    for (int i = 0; i < 20; ++i) {
        generateEnemy(generateLocation(false,false));
    }
}

std::pair<int, int> Generator::generateLocation() {
    // do magic
    int rand = RNG.getRandom(rooms.size());

    std::vector<std::pair<int,int>> emptyCells = rooms[rand];
    int location = RNG.getRandom(emptyCells.size());
    std::pair<int,int> val = rooms[rand][location];
    rooms[rand].erase(rooms[rand].begin() + location);
    return val;
}

void Generator::generatePotion(std::pair<int,int> coords){
	int rand = RNG.getRandom(6);

	if (rand == 0){
		ConcreteRH(coords);
	} else if (rand == 1){
		ConcretePH(coords);
	} else if (rand == 2){
		ConcreteBA(coords);
	} else if (rand == 3){
		ConcreteWA(coords);
	} else if (rand == 4){
		ConcreteBD(coords);
	} else {
		ConcreteWD(coords);
	}
}

bool Generator::generateGold(std::pair<int,int> coords){
	int rand = RNG.getRandom(8);

	if (rand >= 0 and rand <= 4){
		ConcreteGoldStashNormal(coords, 1);
	} else if (rand == 5){
		ConcreteGoldStashGuarded(coords);
		// somehow check for a valid location for dragon
		ConcreteDragon();
	} else {
		ConcreteGoldStashNormal(coords, 2);
	}
}

void Generator::generateEnemy(std::pair<int, int> coords){
	int rand = RNG.getRandom(18);

	if (rand >= 0 and rand <= 3){
		ConcreteWerewolf(coords);
	} else if (rand >= 4 and rand <= 6){
		ConcreteVampire(coords);
	} else if (rand >= 7 and rand <= 11){
		ConcreteGoblin(coords);
	} else if (rand >= 12 and rand <= 13){
		ConcreteTroll(coords);
	} else if (rand >= 14 and rand <= 15){
		ConcretePhoenix(coords);
	} else {
		ConcreteMerchant(coords);
	}
}

std::pair<int, int> Generator::generateLocation(bool player, bool skip) {
	int rand = RNG.getRandom(rooms.size());

	if (player){
		playerRoom = rand;
	}
	if (skip){
		while (rand == playerRoom){
			rand = RNG.getRandom(rooms.size());
		}
	}

	std::vector<std::pair<int,int>> emptyCells = rooms[rand];
	int location = RNG.getRandom(emptyCells.size());
	std::pair<int,int> val = rooms[rand][location];
	rooms[rand].erase(rooms[rand].begin() + location);
	return val;
}

std::pair<int, int> Generator::generateLocation(std::pair<int, int> exclude) {
	int rand = RNG.getRandom(rooms.size());

	std::vector<std::pair<int,int>> emptyCells = rooms[rand];
	int location = RNG.getRandom(emptyCells.size());
	std::pair<int,int> val = rooms[rand][location];
	rooms[rand].erase(rooms[rand].begin() + location);
	return val;
}


