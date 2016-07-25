#include "ConcreteChamber.h"

void ConcreteChamber::addCoord(std::pair<int, int> wallCoord) {
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
    }
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
        for (auto it = row.begin(); it != row.end() - 1; ++it) {
            auto next = it+1;
            if (!(*it).second + 1 == (*next).second) {
                for (int i = (*it).second + 1; i < (*next).second; ++i) {
                    cellCoords.push_back(std::pair<int,int>{(*it).first, i});
                }
            }
        }
    }
    return cellCoords;
}

