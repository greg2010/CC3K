#include "GoldStash.h"

GoldStash::GoldStash(std::pair<int,int>coords):Item{coords}{}

SubjectType GoldStash::getType() {
	return SubjectType::Gold;
}

bool GoldStash::walkable() {
    return false;
}

void GoldStash::taken(Player &p) {
    doTaken(p);
    remove();
}
