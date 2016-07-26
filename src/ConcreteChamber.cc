#include "ConcreteChamber.h"

void ConcreteChamber::addCoord(std::pair<int, int> wallCoord) {
    if (wallCoords.size() <= wallCoord.first - firstRow) {
        wallCoords.resize(wallCoord.first + 1 - firstRow);
    }
    int i = 0;
    while (i < wallCoords[wallCoord.first - firstRow].size() && wallCoords[wallCoord.first - firstRow][i].second < wallCoord.second) ++i;
    wallCoords[wallCoord.first - firstRow].insert(wallCoords[wallCoord.first -firstRow].begin() + i, wallCoord);
    /*
    std::vector<std::pair<int,int>> emptyRow;
    if (wallCoords.size() == 0) {
        wallCoords.push_back(emptyRow);
    } else if (wallCoords.size() <= wallCoord.first) {
        wallCoords.resize(wallCoord.first);
    }


    if (wallCoords[wallCoord.first].size() == 0) {
        wallCoords[wallCoord.first].push_back(wallCoord);
    } else {
        int j = 0;
        while (j < wallCoords[wallCoord.first].size() && wallCoords[wallCoord.first][j].second < wallCoord.second) ++j;
        wallCoords[wallCoord.first].insert(wallCoords[wallCoord.first].begin() + j, wallCoord);
    }*/
}

std::vector<std::pair<int, int>> ConcreteChamber::getCoords() {
    std::vector<std::pair<int,int>> walls;
    for (auto row : wallCoords) {
        for (auto coord : row) {
            walls.push_back(coord);
        }
    }
    return walls;
}

std::vector<std::pair<int, int>> ConcreteChamber::getCellCoords() {
    std::vector<std::pair<int,int>> cellCoords;
    for (auto row : wallCoords) {
        auto it = row.begin();
        auto next = it + 1;
        while (next != row.end() && (*it).second + 1 == (*next).second) {
            ++it;
            ++next;
        }
        if (next != row.end()) {
            for (int i = (*it).second + 1; i < (*next).second; ++i) {
                cellCoords.push_back(std::pair<int, int>{(*it).first, i});
            }
        }
    }
    return cellCoords;
}

ConcreteChamber::ConcreteChamber(int firstRow) : firstRow{firstRow} {

}
