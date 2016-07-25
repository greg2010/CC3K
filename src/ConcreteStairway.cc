#include "ConcreteStairway.h"
using namespace std;

ConcreteStairway::ConcreteStairway(std::pair<int,int>coords):Item{coords}{}

SubjectType ConcreteStairway::getType(){
	return SubjectType::Stairway;
}

bool ConcreteStairway::walkable() {
    return false;
}
