#include "Potion.h"

Potion::Potion(std::pair<int,int> coords):Item{coords},decPot {nullptr}{}

SubjectType Potion::getType(){
	return SubjectType::Potion;
}
