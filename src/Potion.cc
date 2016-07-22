#include "Potion.h"

Potion::Potion(std::pair<int,int> coords):Item{coords},decPot {nullptr}{}

void Potion::push(Potion &other) {
    if (potDec) {
        potDec->push(other);
    } else {
        potDec = std::static_pointer_cast<Potion>(other.shared_from_this());
    }
}

SubjectType Potion::getType(){
	return SubjectType::Potion;
}
