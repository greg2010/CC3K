#include "ConcreteBridgeOld.h"

ConcreteBridgeOld::ConcreteBridgeOld() : vertical{true} { }

void ConcreteBridgeOld::addCoord(std::pair<int, int> bridgeCoord) {
    if (bridgeCoords.size() == 0) {
        bridgeCoords.push_back(bridgeCoord);
        return;
    }
    if (bridgeCoords.size() == 1) {
        if (bridgeCoords[0].first == bridgeCoord.first) {
            vertical = false;
        }
    }
    int i = 0;
    if (vertical) {
        while (i < bridgeCoords.size() && bridgeCoords[i].first < bridgeCoord.first) ++i;
    } else {
        while (i < bridgeCoords.size() && bridgeCoords[i].second < bridgeCoord.second) ++i;
    }
    bridgeCoords.insert(bridgeCoords.begin() + i, bridgeCoord);
}

std::vector<std::pair<int, int>> ConcreteBridgeOld::getCoords() {
    return bridgeCoords;
}
