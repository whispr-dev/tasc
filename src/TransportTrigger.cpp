auto matchedCells = cam->queryAdvanced(grid, 
    [](const Cell& c) { return c.tag == "compute" && c.stack.stk.size() < 3; }

void TransportTrigger::transportDataDelayed(..., int delayCycles);

);