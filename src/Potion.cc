#include "Potion.h"

Potion::Potion(std::pair<int,int> coords):Item{coords},decPot {nullptr}{}

void Potion::push(Potion &other) {
    if (decPot) {
        decPot->push(other);
    } else {
        decPot = std::static_pointer_cast<Potion>(other.shared_from_this());
    }
}
