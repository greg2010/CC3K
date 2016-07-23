//
//  TextDisplay.cc
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "TextDisplay.h"
#include "Subject.h"
#include "Player.h"
#include "Observer.h"

#include <iomanip>
#include <memory>

using namespace std;
TextDisplay::TextDisplay(std::shared_ptr<Player> pc, int currFloor, string race, int width, int height): pc(pc), race(race), currFloor(currFloor), w(width), h(height) {
    charMap[SubjectType::Player] = '@';
    charMap[SubjectType::Goblin] = 'N';
    charMap[SubjectType::Vampire] = 'V';
    charMap[SubjectType::Werewolf] = 'W';
    charMap[SubjectType::Merchant] = 'M';
    charMap[SubjectType::Dragon] = 'D';
    charMap[SubjectType::Phoenix] = 'X';
    charMap[SubjectType::Troll] = 'T';
    charMap[SubjectType::Potion] = 'P';
    charMap[SubjectType::Gold] = 'G';
    charMap[SubjectType::Stairway] = '\\';
}


void TextDisplay::notify(std::shared_ptr<Subject> sub, bool off) {
    if (off){
        grid[sub->getCoordinates().first][sub->getCoordinates().second] = '.';
    }
    else {
        grid[sub->getCoordinates().first][sub->getCoordinates().second] = charMap[sub->getType()];
    }
}

void TextDisplay::notify(std::shared_ptr<Item> item, bool off) {
    if (off){
        grid[item->getCoordinates().first][item->getCoordinates().second] = '.';
    }
    else {
        grid[item->getCoordinates().first][item->getCoordinates().second] = charMap[item->getType()];
    }
}

void TextDisplay::drawLayout(istream &in) {
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            char c;
            in >> std::noskipws >> c;
            grid[row][col] = c;
        }
        
    }
}

friend void operator<<(std::ostream &out, const TextDisplay td) {
    for(int i = 0; i < td.grid.size(); i++){
        for(int j = 0; j < td.grid[i].size(); j++){
            out<<td.grid[i][j];
        }
        out << endl;
    }
    
    out << "Race: " << td->race
    << " Gold: "<< td->pc->getGold()
    << right << setw(td->grid[0].size()-27) << "Floor "<< td->currFloor << endl
    << "HP: "<< td->pc->getHP() << endl
    << "Atk: "<< td->pc->getAttack() << endl
    << "Def: "<< td->pc->getDefence() << endl
    << "Action: "<<endl;
    
}
