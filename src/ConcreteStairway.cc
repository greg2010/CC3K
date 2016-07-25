#include "ConcreteStairway.h"
using namespace std;

SubjectType ConcreteStairway::getType(){
	return SubjectType::Stairway;
}

bool ConcreteStairway::walkable() {
    return true;
}