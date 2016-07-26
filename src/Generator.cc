#include <memory>
#include "Floor.h"
#include "Generator.h"
#include "ConcreteChamber.h"
#include "ConcreteRH.h"
#include "ConcretePH.h"
#include "ConcreteBA.h"
#include "ConcreteWA.h"
#include "ConcreteBD.h"
#include "ConcreteWD.h"
#include "ConcreteDragon.h"
#include "ConcreteWerewolf.h"
#include "ConcreteVampire.h"
#include "ConcreteGoblin.h"
#include "ConcreteTroll.h"
#include "ConcreteStairway.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"
#include "ConcretePhoenix.h"
#include "ConcreteMerchant.h"

Generator::Generator(std::shared_ptr<Floor> floor,
                     std::shared_ptr<TextDisplay> display,
                     std::shared_ptr<Player> player, unsigned int seed) : FloorPtr{floor},
                                                                          PlayerPtr{player},
                                                                          RNG{RandGen::getInstance(seed)}{
									  
										  std::vector<std::shared_ptr<ConcreteChamber>> chambers = FloorPtr->getChamber();
										  
										  for (auto ch : chambers){
											  rooms.push_back(ch->getCellCoords());
										  }
										
									  }

void Generator::generate() {
    std::pair<int,int> playerCoords = generateLocation(true, false);
    PlayerPtr->assignCoords(playerCoords);
	FloorPtr->addToObjects(PlayerPtr);
	PlayerPtr->attach(FloorPtr);
    std::pair<int,int> stairwayCoords = generateLocation(false, true);
	auto stairway = std::make_shared<ConcreteStairway>(stairwayCoords);
	stairway->attach(FloorPtr);
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

void Generator::generatePotion(std::pair<int,int> coords){
	int rand = RNG.getRandom(6);

	if (rand == 0){
        std::shared_ptr<ConcreteRH> pot = std::make_shared<ConcreteRH>(coords);
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	} else if (rand == 1){
        std::shared_ptr<ConcretePH> pot = std::make_shared<ConcretePH>(coords);
        //pot->attach(std::dynamic_pointer_cast<Observer>(FloorPtr));
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	} else if (rand == 2){
        std::shared_ptr<ConcreteBA> pot = std::make_shared<ConcreteBA>(coords);
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	} else if (rand == 3){
        std::shared_ptr<ConcreteWA> pot = std::make_shared<ConcreteWA>(coords);
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	} else if (rand == 4){
        std::shared_ptr<ConcreteBD> pot = std::make_shared<ConcreteBD>(coords);
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	} else {
        std::shared_ptr<ConcreteWD> pot = std::make_shared<ConcreteWD>(coords);
		FloorPtr->addToObjects(pot);
        pot->attach(FloorPtr);
	}
}

bool Generator::generateGold(std::pair<int,int> coords){
	int rand = RNG.getRandom(8);

	if (rand >= 0 and rand <= 4){
		auto gold = std::make_shared<ConcreteGoldStashNormal>(coords, 1);
		FloorPtr->addToObjects(gold);
		gold->attach(FloorPtr);
	} else if (rand == 5){
		auto gold = std::make_shared<ConcreteGoldStashGuarded>(coords, 6);
		FloorPtr->addToObjects(gold);
		gold->attach(FloorPtr);
		// somehow check for a valid location for dragon
		// TODO: ConcreteDragon();
	} else {
		auto gold = std::make_shared<ConcreteGoldStashNormal>(coords, 2);
		FloorPtr->addToObjects(gold);
		gold->attach(FloorPtr);
	}
    return true;
}

void Generator::generateEnemy(std::pair<int, int> coords){
	int rand = RNG.getRandom(18);

	if (rand >= 0 and rand <= 3){
        std::shared_ptr<ConcreteWerewolf> enemy = std::make_shared<ConcreteWerewolf>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
	} else if (rand >= 4 and rand <= 6){
        std::shared_ptr<ConcreteVampire> enemy = std::make_shared<ConcreteVampire>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
	} else if (rand >= 7 and rand <= 11){
        std::shared_ptr<ConcreteGoblin> enemy = std::make_shared<ConcreteGoblin>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
	} else if (rand >= 12 and rand <= 13){
        std::shared_ptr<ConcreteTroll> enemy = std::make_shared<ConcreteTroll>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
	} else if (rand >= 14 and rand <= 15){
        std::shared_ptr<ConcretePhoenix> enemy = std::make_shared<ConcretePhoenix>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
	} else {
        std::shared_ptr<ConcreteMerchant> enemy = std::make_shared<ConcreteMerchant>(coords);
		FloorPtr->addToObjects(enemy);
        enemy->attach(FloorPtr);
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

