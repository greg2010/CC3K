#ifndef A05_CHARACTER_H
#define A05_CHARACTER_H


#include "Subject.h"

class Character : Subject {
public:
    Character(int HP, int atk, int def, std::pair<int,int> coords);
    unsigned int getHP();
    unsigned int getAttack();
    unsigned int getDefence();
    bool move(std::string dir);
    void attackedBy(std::shared_ptr<Character> attacker);
    unsigned int getGold();
    bool hasMoved();
    void resetMove();
private:
    bool hasMovedThisTurn;
    int HP;
    int atk;
    int def;
    int gold;
};



#endif //A05_CHARACTER_H
