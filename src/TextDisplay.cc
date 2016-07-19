//
//  TextDisplay.cpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "TextDisplay.h"
#include "Subject.h"

TextDisplay::TextDisplay(int width, int height): w(width), h(height) {
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


void notify(std::shared_ptr<Subject> sub) {
    
}
            
void notify(std::shared_ptr<Item> item) {
    
}