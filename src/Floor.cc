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
#include "ConcreteStairway.h"
#include "ConcreteRH.h"
#include "ConcretePH.h"
#include "ConcreteBA.h"
#include "ConcreteWA.h"
#include "ConcreteBD.h"
#include "ConcreteWD.h"
#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"
#include "ConcreteDoor.h"
#include "ConcreteWallH.h"
#include "ConcreteWallV.h"
#include "ConcreteBridge.h"
#include "Game.h"
#include "Subject.h"
#include "ConcreteCell.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Floor::Floor(std::shared_ptr<Player> player, int currFloor, string playerType, int seed, std::shared_ptr<TextDisplay> td) : player(player), currFloor(currFloor), playerType(playerType), seed(seed), td(td) {
}

Floor::~Floor() {}

void Floor::readLayout(ifstream &in){
    //td->drawLayout(in);
    bool doGeneration = true;
    vector<shared_ptr<Subject>> empty;
    for (int row = 0; row < rows; row++) {
        floorMap.push_back(empty);
        for (int col = 0; col < cols; col++) {
            char c;
            in >> noskipws >> c;
            switch (c) {
                case ' ':
                    floorMap[row].push_back(nullptr);
                    break;
                case '|':
                    floorMap[row].push_back(make_shared<ConcreteWallV>(make_pair(row,col)));
                    break;
                case '-':
                    floorMap[row].push_back(make_shared<ConcreteWallH>(make_pair(row,col)));
                    break;
                case '.':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    break;
                case '+':
                    floorMap[row].push_back(make_shared<ConcreteDoor>(make_pair(row,col)));
                    break;
                case '#':
                    floorMap[row].push_back(make_shared<ConcreteBridge>(make_pair(row,col)));
                    break;
                case '\\':
                    floorMap[row].push_back(make_shared<ConcreteStairway>(make_pair(row,col)));
                    break;
                case '@':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    player->assignCoords(make_pair(row, col));
                    objects.push_back(player);
                    player->attach(shared_from_this());
                    doGeneration = false;
                    break;
                case 'N':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteGoblin>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'V':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteVampire>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'T':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteTroll>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'M':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteMerchant>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'D':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteDragon>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'P':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcretePhoenix>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'W':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteWerewolf>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case 'X':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcretePhoenix>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '0':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteRH>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '1':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteBA>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '2':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteBD>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '3':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcretePH>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '4':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteWA>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '5':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteWD>(make_pair(row,col)));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '6':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row,col), 1));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '7':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row, col), 2));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '8':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteGoldStashNormal>(make_pair(row, col), 4));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                case '9':
                    floorMap[row].push_back(make_shared<ConcreteCell>(make_pair(row,col)));
                    objects.push_back(make_shared<ConcreteGoldStashGuarded>(make_pair(row, col), 6));
                    (objects.end() - 1)->operator*().attach(shared_from_this());
                    break;
                default: break;
            }
            if (c == '\n') continue;
            if (floorMap[row][col]) floorMap[row][col]->attach(shared_from_this());
        }
    }
    if (doGeneration) {
        shared_ptr<Generator> gen = make_shared<Generator>(shared_from_this(),td, player, seed);
        gen->generate();
    }
    for (int i = 1; i < floorMap.size() - 1; ++i) {
        for (int j = 1; j < floorMap[i].size() - 1; ++j) {
            if (floorMap[i][j] && (floorMap[i][j]->getType() == SubjectType::WallH || floorMap[i][j]->getType() == SubjectType::WallV) && !this->searchInChambers(i, j)) {
                this->createNewChamber(i, j);
            }
        }
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
    td->notify(getObjectAtCoords(s->getCoordinates()), true);
    // this->coord = s->getCoordinates();
    /*
    if ((s->getType() != SubjectType::RH || s->getType() != SubjectType::PH || s->getType() != SubjectType::BA || s->getType() != SubjectType::WA || s->getType() != SubjectType::BD || s->getType() != SubjectType::WD) && (s->getType() != SubjectType::Gold)){
        shared_ptr<Character> character = dynamic_pointer_cast<Character> (s);
        this->gold = character->getGold();
        this->hp = character->getHP();
        this->atk = character->getAttack();
        this->def = character->getDefence();
    }
     */
}


void Floor::deleteSubject(std::shared_ptr<Subject> s) {
    s->Subject::remove();

 }

shared_ptr<Subject> Floor::getObjectAtCoords(pair<int, int> coor) {
    for (auto &sub : objects) {
        if (sub->getCoordinates() == coor) return sub;
    }
    return floorMap[coor.first][coor.second];
}

vector<std::shared_ptr<Subject> > Floor::adjacent(std::shared_ptr<Subject> s) {
    pair<int, int> coor = s->getCoordinates();
    vector<std::shared_ptr<Subject> > neighbors;
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first - 1, coor.second - 1)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first - 1, coor.second)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first - 1, coor.second + 1)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first, coor.second + 1)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first, coor.second - 1)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first + 1, coor.second + 1)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first + 1, coor.second)));
    neighbors.push_back(getObjectAtCoords(make_pair(coor.first + 1, coor.second - 1)));
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
                pair<int,int> oldCoords = s->getCoordinates();
                dynamic_pointer_cast<Character> (s)->move(coor);
                td->notify(getObjectAtCoords(oldCoords), false);
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
    shared_ptr<ConcreteChamber> newChamber = make_shared<ConcreteChamber>(row);
    chambers.push_back(newChamber);
    int newRow = row, newCol = col;
    do {
        if (floorMap[newRow][newCol + 1] && (floorMap[newRow][newCol + 1]->getType() == SubjectType::WallV ||
                                             floorMap[newRow][newCol + 1]->getType() == SubjectType::WallH ||
                floorMap[newRow][newCol + 1]->getType() == SubjectType::Door) && (!searchInChambers(newRow, newCol + 1))) {
            ++newCol;
        } else if (floorMap[newRow + 1][newCol] && (floorMap[newRow + 1][newCol]->getType() == SubjectType::WallV ||
                                                    floorMap[newRow + 1][newCol]->getType() == SubjectType::WallH ||
                floorMap[newRow + 1][newCol]->getType() == SubjectType::Door) && (!searchInChambers(newRow + 1, newCol))) {
            ++newRow;
        } else if (floorMap[newRow][newCol - 1] && (floorMap[newRow][newCol - 1]->getType() == SubjectType::WallV ||
                                                    floorMap[newRow][newCol - 1]->getType() == SubjectType::WallH ||
                floorMap[newRow][newCol - 1]->getType() == SubjectType::Door) && (!searchInChambers(newRow, newCol - 1))) {
            --newCol;
        } else if (floorMap[newRow - 1][newCol] && (floorMap[newRow - 1][newCol]->getType() == SubjectType::WallV ||
                                                    floorMap[newRow - 1][newCol]->getType() == SubjectType::WallH ||
                floorMap[newRow - 1][newCol]->getType() == SubjectType::Door) && (!searchInChambers(newRow - 1, newCol))) {
            --newRow;
        }
        newChamber->addCoord(make_pair(newRow, newCol));

    } while (newRow != row || newCol != col);
}

                       
vector<shared_ptr<ConcreteChamber> > Floor::getChamber() {
    return this->chambers;
}

void Floor::usePotion(string dir) {
    vector<std::shared_ptr<Subject> > neighbors = adjacent(player);
    pair<int,int> coor = player->getCoordinates();
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
    auto obj = getObjectAtCoords(coor);
    if (obj->getType() == SubjectType::RH || obj->getType() == SubjectType::PH || obj->getType() == SubjectType::BA || obj->getType() == SubjectType::WA || obj->getType() == SubjectType::BD || obj->getType() == SubjectType::WD) {
        dynamic_pointer_cast<Potion>(obj)->taken(*player);
        td->potionMessage(obj);
    }
}

void Floor::attack(string dir) {
    vector<std::shared_ptr<Subject> > neighbors = adjacent(player);
    auto coor = player->getCoordinates();
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
    auto obj = getObjectAtCoords(coor);
    if (obj->getType() == SubjectType::Goblin || obj->getType() == SubjectType::Vampire || obj->getType() == SubjectType::Troll || obj->getType() == SubjectType::Merchant || obj->getType() == SubjectType::Dragon || obj->getType() == SubjectType::Phoenix || obj->getType() == SubjectType::Werewolf) {
        int damage = (dynamic_pointer_cast<Character>(obj))->attackedBy(player);
        td->attackMessage(player, obj, damage);
    }
}

void Floor::enemyTurn() {
    for (auto &obj : objects) {
        if ((obj->getType() == SubjectType::Goblin || obj->getType() == SubjectType::Vampire ||
             obj->getType() == SubjectType::Troll || obj->getType() == SubjectType::Merchant ||
             obj->getType() == SubjectType::Dragon || obj->getType() == SubjectType::Phoenix ||
             obj->getType() == SubjectType::Werewolf) &&
            ((dynamic_pointer_cast<Enemy>(obj))->isMoving()) &&
            (!(dynamic_pointer_cast<Character>(obj))->hasMoved())) {
            vector<std::shared_ptr<Subject> > neighbors = adjacent(obj);
            for (auto &sub : neighbors) {
                if (sub->getType() == SubjectType::Player &&
                    (dynamic_pointer_cast<Enemy>(obj)->isHostile())) {
                    doAttack(obj);
                }
                else {
                    doMove(obj);
                }
                break;
            }
        }
    }
    for (auto &obj : objects) {
        if (obj->getType() == SubjectType::Goblin || obj->getType() == SubjectType::Vampire ||
             obj->getType() == SubjectType::Troll || obj->getType() == SubjectType::Merchant ||
             obj->getType() == SubjectType::Dragon || obj->getType() == SubjectType::Phoenix ||
             obj->getType() == SubjectType::Werewolf) {
            (dynamic_pointer_cast<Character>(obj))->resetMove();
        }
    }
    sort(objects.begin(), objects.end(), [](shared_ptr<Subject> &lhs, shared_ptr<Subject> &rhs) {
        if (lhs->getCoordinates().first < rhs->getCoordinates().first) return true;
        else return lhs->getCoordinates().first == rhs->getCoordinates().first && lhs->getCoordinates().second < rhs->getCoordinates().second;
    });
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
    vector<std::shared_ptr<Subject> > validNeighbors;
    for (auto ptr : neighbors) {
        if (ptr && ptr->walkable()) {
            validNeighbors.push_back(ptr);
        }
    }
    if (validNeighbors.size() == 0) return;
    RandGen& RNG = RandGen::getInstance(seed);
    int choice = RNG.getRandom(validNeighbors.size());
    auto currCoords = enemy->getCoordinates();
    dynamic_pointer_cast<Character>(enemy)->move(validNeighbors[choice]->getCoordinates());
    getObjectAtCoords(currCoords)->notifyObservers();
}
                


