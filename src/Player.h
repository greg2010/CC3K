#ifndef A05_PLAYER_H
#define A05_PLAYER_H

#include <memory>
#include "Character.h"
#include "Potion.h"

class ConcreteGoldStashNormal;
class Potion;
class PotHP;
class ConcreteGoldStashGuarded;
class ConcreteStairway;

class Player : public Character {
public:
    Player(int HP, int atk, int def, std::pair<int,int> coords);
    void interact(ConcreteGoldStashNormal &item);
    void interact(ConcreteGoldStashGuarded &item);
    void interact(Potion &item);
    void interact(PotHP &hpPot);
    void interact(ConcreteStairway &item);

    SubjectType getType();

     void assignCoords (std::pair<int, int> coords);

    virtual unsigned int getAttack();
    virtual unsigned int getDefence();

    virtual int getScore();

    void resetPotions();

    void pushPotion(Potion &pot); // Adds potion as decorator
protected:
    virtual void doInteract(ConcreteGoldStashNormal &item);
    virtual void doInteract(ConcreteGoldStashGuarded &item);

    virtual void doInteract(PotHP &hpPot);

    int getPotAttack();
    int getPotDefence();

private:
    std::shared_ptr<Potion> potDec;
};


#endif //A05_PLAYER_H
