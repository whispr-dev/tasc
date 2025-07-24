#pragma once
#include "CAM.h"

class TransportTrigger {
public:
    CAM* cam;
    TransportTrigger(CAM* cam);

    void transportData(std::vector<std::vector<Cell>>& grid, const std::string& tag, int data, const std::string& operation);
};
