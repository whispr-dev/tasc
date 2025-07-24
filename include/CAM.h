#pragma once
#include "Cell.h"
#include <vector>
#include <string>

class CAM {
public:
    std::vector<Cell*> queryCellsByTag(const std::vector<std::vector<Cell>>& grid, const std::string& tag);
};
