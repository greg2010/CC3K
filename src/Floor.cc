//
//  Floor.cc
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//
//
#include "Floor.h"
#include "Player.h"
#include "Generator.h"
#include "TextDisplay.h"
#include "ConcreteChamber.h"
#include "ConcreteGoblin.h"
#include "ConcreteVampire.h"
#include "ConcreteTroll.h"
#include "ConcreteMerchant.h"
#include "ConcreteDragon.h"
#include "ConcretePhoenix.h"
#include "ConcreteWerewolf.h"
#include "ConcreteRH.h"
#include "ConcretePH.h"
#include "ConcreteBA.h"
#include "ConcreteWA.h"
#include "ConcreteBD.h"
#include "ConcreteWD.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"
#include "Door.h"
#include "Wall.h"
#include "Bridge.h"
#include "Game.h"
#include "Subject.h"
#include "Cell.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Floor::Floor(std::shared_ptr<Player> player, int currFloor, string playerType, fstream& file, int seed, std::shared_ptr<TextDisplay> td) : player(player), currFloor(currFloor), playerType(playerType), file(file), seed(seed), td(td) {
	
}

Floor::~Floor() {}

void Floor::readLayout(istream &in){
    td->drawLayout(in);
    bool doGeneration = true;
    vector<shared_ptr<Subject>> empty;
    for (int row = 0; row < rows; row++) {
        floorMap.push_back(empty);
        for (int col = 0; col < cols; col++) {
            char c;
            in >> std::noskipws >> c;
            switch (c) {
                case ' ':
                    floorMap[row].push_back(nullptr);
                    break;
                case '|':
                    floorMap[row].push_back(make_shared<Wall>(make_pair(row,col)));
                    break;
                case '-':
                    floorMap[row].push_back(make_shared<Wall>(make_pair(row,col)));
                    break;
                case '.':
                    floorMap[row].push_back(make_shared<Cell>(make_pair(row,col)));
                    break;
                case '+':
                    floorMap[row].push_back(make_shared<Door>(make_pair(row,col)));
                    break;
                case '#':
                    floorMap[row].push_back(make_shared<Bridge>(make_pair(row,col)));
                    break;
                case '@':
                    player->assignCoords(make_pair(row, col));
                    doGeneration = false;
                    break;
                case 'N':
                    floorMap[row].push_back(make_shared<ConcreteGoblin>(make_pair(row,col)));
                    break;
                case 'V':
                    floorMap[row].push_back(make_shared<ConcreteVampire>(make_pair(row,col)));
                    break;
                case 'T':
                    floorMap[row].push_back(make_shared<ConcreteTroll>(make_pair(row,col)));
                    break;
                case 'M':
                    floorMap[row].push_back(make_shared<ConcreteMerchant>(make_pair(row,col)));
                    break;
                case 'D':
                    floorMap[row].push_back(make_shared<ConcreteDragon>(make_pair(row,col)));
                    break;
                case 'P':
                    floorMap[row].push_back(make_shared<ConcretePhoenix>(make_pair(row,col)));
                    break;
                case 'W':
                    floorMap[row].push_back(make_shared<ConcreteWerewolf>(make_pair(row,col)));
                    break;
                case '0':
                    floorMap[row].push_back(make_shared<ConcreteRH>(make_pair(row,col)));
                    break;
                case '1':
                    floorMap[row].push_back(make_shared<ConcreteBA>(make_pair(row,col)));
                    break;
                case '2':
                    floorMap[row].push_back(make_shared<ConcreteBD>(make_pair(row,col)));
                    break;
                case '3':
                    floorMap[row].push_back(make_shared<ConcretePH>(make_pair(row,col)));
                    break;
                case '4':
                    floorMap[row].push_back(make_shared<ConcreteWA>(make_pair(row,col)));
                    break;
                case '5':
                    floorMap[row].push_back(make_shared<ConcreteWD>(make_pair(row,col)));
                    break;
                case '6':
                    floorMap[row].push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row,col), 1));
                    break;
                case '7':
                    floorMap[row].push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row, col), 2));
                    break;
                case '8':
                    floorMap[row].push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row, col), 4));
                    break;
                case '9':
                    floorMap[row].push_back(make_shared<ConcreteGoldStashGuarded>(make_pair(row, col), 6));
                    break;
                default: break;
            }
        }
    }
    if (doGeneration) {
        shared_ptr<Generator> gen = make_shared<Generator>(shared_from_this(),td, player, seed);
        gen->generate();
    }
    int coordRow = 0;
    int coordCol = 0;
    for (auto &row : floorMap) {
        for (auto &sub : row) {
            if (sub->getType() == SubjectType::Wall && !this->searchInChambers(coordRow, coordCol)) {
                this->createNewChamber(coordRow, coordCol);
            }
            ++coordCol;
        }
        coordCol = 0;
        ++coordRow;
    }
        /*for (auto objType : content) {
            if ((objType.second == ObjectType::Wall_v || objType.second == ObjectType::Wall_h) && !this->searchInChambers(coordRow, coordCol)){
                this->createNewChamber(coordRow, coordCol);
            }
            ++coordCol;
            if (coordCol == 79) {
                coordCol = 0;
                ++coordRow;
            }
        }
         */
}

void Floor::notify(std::shared_ptr<Subject> s, bool off){
    
    if(!s->isVisible()) td->notify(s, true);
    this->coord = s->getCoordinates();
    if ((s->getType() != SubjectType::RH || s->getType() != SubjectType::PH || s->getType() != SubjectType::BA || s->getType() != SubjectType::WA || s->getType() != SubjectType::BD || s->getType() != SubjectType::WD) && (s->getType() != SubjectType::Gold)){
        shared_ptr<Character> character = dynamic_pointer_cast<Character> (s);
        this->gold = character->getGold();
        this->hp = character->getHP();
        this->atk = character->getAttack();
        this->def = character->getDefence();
    }
}


void Floor::deleteSubject(std::shared_ptr<Subject> s) {
    s->Subject::remove();
 }

vector<std::shared_ptr<Subject> > Floor::adjacent(std::shared_ptr<Subject> s) {
    pair<int, int> coor = s->getCoordinates();
    vector<std::shared_ptr<Subject> > neighbors;
    
    neighbors.push_back(floorMap[coor.first - 1][coor.second - 1]);
    neighbors.push_back(floorMap[coor.first - 1][coor.second]);
    neighbors.push_back(floorMap[coor.first - 1][coor.second + 1]);
    neighbors.push_back(floorMap[coor.first][coor.second + 1]);
    neighbors.push_back(floorMap[coor.first + 1][coor.second + 1]);
    neighbors.push_back(floorMap[coor.first + 1][coor.second]);
    neighbors.push_back(floorMap[coor.first + 1][coor.second - 1]);
    return neighbors;
}

bool Floor::move(string dir, std::shared_ptr<Subject> s) {
    // it might be better if move receives set of coods instead of dir
    vector<std::shared_ptr<Subject> > neighbors = adjacent(s);
    pair<int, int> coor = s->getCoordinates();
    int i;
    if (dir == "no") {
        i = 1;
        coor.first--;
    }
    else if (dir == "so") {
        i = 5;
        coor.first++;
    }
    else if (dir == "ea") {
        i = 3;
        coor.second++;
    }
    else if (dir == "we") {
        i = 7;
        coor.second--;
    }
    else if (dir == "ne") {
        i = 2;
        coor.first--;
        coor.second++;
    }
    else if (dir == "nw") {
        i = 0;
        coor.first--;
        coor.second--;
    }
    else if (dir == "se") {
        i = 4;
        coor.first++;
        coor.second++;
    }
    else if (dir == "sw") {
        i = 6;
        coor.first++;
        coor.second--;
    }
    for (auto &neighbor : neighbors) {
        if (neighbor && neighbor->getCoordinates() == coor) {
            if (s->getType() == SubjectType::Player && neighbor->getType() == SubjectType::Stairway) {
                game->generateNextFloor();
                return true;
            }
            if (neighbor->walkable()) {
                td->notify(s, true);
                dynamic_pointer_cast<Character> (s)->move(coor);
                td->notify(s, false);
                return true;
            }
        }
    }
    return false;
}
                       
bool Floor::searchInChambers(int row, int col){
    for (auto &ch : chambers) {
        auto coords = ch->getCoords();
        if(find(coords.begin(), coords.end(), make_pair(row, col)) != coords.end())  return true;
    }
    return false;
}
                       
void Floor::createNewChamber(int row, int col) {
    shared_ptr<ConcreteChamber> newChamber = make_shared<ConcreteChamber>();
    int newRow = row, newCol = col;
    do {
        newChamber->addCoord(make_pair(newRow, newCol));
        if (floorMap[newRow][newCol + 1] && floorMap[newRow][newCol + 1]->getType() == SubjectType::Wall) {
            ++newCol;
        } else if (floorMap[newRow + 1][newCol] && floorMap[newRow + 1][newCol]->getType() == SubjectType::Wall) {
            ++newRow;
        } else if (floorMap[newRow][newCol - 1] && floorMap[newRow][newCol - 1]->getType() == SubjectType::Wall) {
            --newCol;
        }  else if (floorMap[newRow - 1][newCol] && floorMap[newRow - 1][newCol]->getType() == SubjectType::Wall) {
            --newRow;
        }
        
    } while (newRow != row && newCol != col);
    chambers.push_back(newChamber);
}

                       
vector<shared_ptr<ConcreteChamber> > Floor::getChamber() {
    return this->chambers;
}

void Floor::usePotion(string dir) {
    vector<std::shared_ptr<Subject> > neighbors = adjacent(player);
    int i;
    if (dir =="no"){
        i = 1;
    }
    else if(dir == "so"){
        i = 5;
    }
    else if(dir == "ea"){
        i = 3;
    }
    else if(dir == "we"){
        i = 7;
    }
    else if(dir == "ne"){
        i = 2;
    }
    else if(dir == "nw"){
        i = 0;
    }
    else if(dir == "se"){
        i = 4;
    }
    else if(dir == "sw"){
        i = 6;
    }
    if (neighbors[i]->getType() == SubjectType::RH || neighbors[i]->getType() == SubjectType::PH || neighbors[i]->getType() == SubjectType::BA || neighbors[i]->getType() == SubjectType::WA || neighbors[i]->getType() == SubjectType::BD || neighbors[i]->getType() == SubjectType::WD) {
        dynamic_pointer_cast<Potion>(neighbors[i])->taken(*player);
        td->potionMessage(neighbors[i]);
    }
}

void Floor::attack(string dir) {
    vector<std::shared_ptr<Subject> > neighbors = adjacent(player);
    int i;
    if (dir =="no"){
        i = 1;
    }
    else if(dir == "so"){
        i = 5;
    }
    else if(dir == "ea"){
        i = 3;
    }
    else if(dir == "we"){
        i = 7;
    }
    else if(dir == "ne"){
        i = 2;
    }
    else if(dir == "nw"){
        i = 0;
    }
    else if(dir == "se"){
        i = 4;
    }
    else if(dir == "sw"){
        i = 6;
    }
    if (neighbors[i]->getType() == SubjectType::Goblin || neighbors[i]->getType() == SubjectType::Vampire || neighbors[i]->getType() == SubjectType::Troll || neighbors[i]->getType() == SubjectType::Merchant || neighbors[i]->getType() == SubjectType::Dragon || neighbors[i]->getType() == SubjectType::Phoenix || neighbors[i]->getType() == SubjectType::Werewolf) {
        int damage = (dynamic_pointer_cast<Character>(neighbors[i]))->attackedBy(player);
        td->attackMessage(player, neighbors[i], damage);
    }
}

void Floor::enemyTurn() {
    for (auto &row : floorMap) {
        for (auto &enemy : row) {
            if ((enemy->getType() == SubjectType::Goblin || enemy->getType() == SubjectType::Vampire || enemy->getType() == SubjectType::Troll || enemy->getType() == SubjectType::Merchant || enemy->getType() == SubjectType::Dragon || enemy->getType() == SubjectType::Phoenix || enemy->getType() == SubjectType::Werewolf) && (!(dynamic_pointer_cast<Character>(enemy))->hasMoved())) {
                 vector<std::shared_ptr<Subject> > neighbors = adjacent(enemy);
                for (auto &sub : neighbors) {
                    if (sub->getType() == SubjectType::Player) {
                        doAttack(enemy);
                    }
                    else {
                        doMove(enemy);
                    }
                }
            }
            
        }
    }
    for (auto &row : floorMap) {
        for (auto &enemy : row) {
            (dynamic_pointer_cast<Character>(enemy))->resetMove();
        }
    }
}

void Floor::doAttack(std::shared_ptr<Subject> attacker) {
    RandGen& RNG = RandGen::getInstance(seed);
    bool hit = RNG.getRandom(2);
    if (hit) {
        int damage = (dynamic_pointer_cast<Character>(player))->attackedBy(dynamic_pointer_cast<Character>(attacker));
        td->attackMessage(attacker, player, damage);
    }
}
                
void Floor::doMove(std::shared_ptr<Subject> enemy) {
    vector<std::shared_ptr<Subject> > neighbors = adjacent(enemy);
    std::remove_if(neighbors.begin(), neighbors.end(), [](auto ptr) {
                    if(ptr) {
                        return true;
                    } else {
                        return false;
                    }
    });
	
    if (neighbors.size() == 0) return;
    RandGen& RNG = RandGen::getInstance(seed);
    int choice = RNG.getRandom(neighbors.size());
    
}
                


