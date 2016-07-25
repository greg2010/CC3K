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
    string message = " Player character has spawned.";
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

void operator<<(std::ostream &out, const TextDisplay &td) {
    for(int i = 0; i < td.grid.size(); i++){
        for(int j = 0; j < td.grid[i].size(); j++){
            out<<td.grid[i][j];
        }
        out << endl;
    }
    
    out << "Race: " << td.race
    << " Gold: "<< td.pc->getGold()
    << right << setw(td.grid[0].size()-27) << "Floor "<< td.currFloor << endl
    << "HP: "<< td.pc->getHP() << endl
    << "Atk: "<< td.pc->getAttack() << endl
    << "Def: "<< td.pc->getDefence() << endl
    << "Action: " << td.message <<endl;

}
void TextDisplay::drawLayout(istream &in) {
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            char c;
            in >> std::noskipws >> c;
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5') {
               c = 'P';
            }
            if (c == '6' || c == '7' || c == '8' || c == '8') {
                c = 'G';
            }
            grid[row][col] = c;
        }
    }
}

string TextDisplay::potionMessage(std::shared_ptr<Subject> sub) {
    if (sub->getType() == SubjectType :: RH) message = "RH";
    else if (sub->getType() == SubjectType :: PH) message = "PH";
    else if (sub->getType() == SubjectType :: BA) message = "BA";
    else if (sub->getType() == SubjectType :: WA) message = "WA";
    else if (sub->getType() == SubjectType :: BD) message = "BD";
    else if (sub->getType() == SubjectType :: WD) message = "WD";
    else return  "";
    message = "PC uses " + message;
    return message;
}

string TextDisplay::attackMessage(shared_ptr<Subject> attacker, shared_ptr<Subject> beingAttacked, int damage) {
    if (attacker->getType() == SubjectType::Player) {
        message = " PC deals " + to_string(damage) + " damage to " + charMap[beingAttacked->getType()] + " (" + beingAttacked->getHP() + " HP). ";
    }
    
}


