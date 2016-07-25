#ifndef A05_CHARACTER_H
#define A05_CHARACTER_H

#include "Subject.h"

class Character : public Subject {
public:
    Character(int HP, int atk, int def, std::pair<int,int> coords); // Constructs character
    unsigned int getHP();
    virtual unsigned int getAttack();
    virtual unsigned int getDefence();
    void move(std::pair<int,int> newCoords); // Moves chararcter in direction dir. Assumes that new coords are valid
    virtual int attackedBy(std::shared_ptr<Character> attacker); // Handles attacks
    unsigned int getGold();
    bool hasMoved(); // getter for hasMovedThisTurn
    void resetMove(); // resets hasMovedThisTurn
    virtual ~Character() = 0;

protected:
    void addGold(int val);
    void changeHP(int val);
private:
    bool hasMovedThisTurn;
    int HP;
    int atk;
    int def;
    int gold;
};



#endif //A05_CHARACTER_H
