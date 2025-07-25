#pragma once
#include "Cell.h"
#include "CAM.h"
#include "TransportTrigger.h"
#include <vector>

class TASCGrid {
public:
    std::vector<std::vector<Cell>> grid;
    CAM cam;
    TransportTrigger transport;

    TASCGrid(int width, int height);
    void step(); // Single step of simulation
    std::vector<Cell*> getNeighbors(int x, int y);
};
