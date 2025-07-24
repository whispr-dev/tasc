#pragma once
#include "StackMachine.h"
#include <string>

class Cell {
public:
    StackMachine stack;
    std::string tag;
    Cell();

    void triggerOperation(const std::string& op);
    void evolve(); // CA evolution logic
    void evolve(const std::vector<Cell*>& neighbors);
    void applySelfModification(const std::string& modCommand);
};
