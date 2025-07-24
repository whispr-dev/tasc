#include "TASCGrid.h"
#include <iostream>

int main() {
    TASCGrid tasc(10, 10);

    // Initial tagging for demo
    tasc.grid[2][3].tag = "add";
    tasc.grid[5][7].tag = "mul";

    // Trigger transports
    tasc.transport.transportData(tasc.grid, "add", 3, "push");
    tasc.transport.transportData(tasc.grid, "add", 4, "push");
    tasc.transport.transportData(tasc.grid, "add", 0, "add"); // data ignored, triggers add

    tasc.step(); // Evolve one step

    int result = tasc.grid[2][3].stack.pop();
    std::cout << "Result in cell [2,3]: " << result << std::endl;

    return 0;
}
