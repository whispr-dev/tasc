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

void printGridTags(const TASCGrid& tasc) {
    for (const auto& row : tasc.grid) {
        for (const auto& cell : row) {
            std::cout << cell.tag << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    TASCGrid tasc(5, 5);

    // Set initial tags
    tasc.grid[1][1].tag = "add";
    tasc.grid[1][2].tag = "add";
    tasc.grid[2][1].tag = "mul";
    tasc.grid[3][3].tag = "mul";

    std::cout << "Initial Grid Tags:\n";
    printGridTags(tasc);

    // Evolve once
    tasc.step();

    std::cout << "After 1st Evolution Step:\n";
    printGridTags(tasc);

    // Evolve again
    tasc.step();

    std::cout << "After 2nd Evolution Step:\n";
    printGridTags(tasc);

    return 0;
}
