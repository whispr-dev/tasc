#include "TASCGrid.h"

// Constructor reminder
TASCGrid::TASCGrid(int width, int height)
    : grid(height, std::vector<Cell>(width)), transport(&cam) {}

// Get neighbors (Moore neighborhood: 8 neighbors around a cell)
std::vector<Cell*> TASCGrid::getNeighbors(int x, int y) {
    std::vector<Cell*> neighbors;
    int height = grid.size();
    int width = grid[0].size();

    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself
            int nx = x + dx;
            int ny = y + dy;

            // Check boundaries
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                neighbors.push_back(&grid[ny][nx]);
            }
        }
    }
    return neighbors;
}

// Grid evolution step
void TASCGrid::step() {
    int height = grid.size();
    int width = grid[0].size();

    // Temporary copy to hold evolved states
    auto gridCopy = grid;

    // Evolve each cell based on its neighbors
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto neighbors = getNeighbors(x, y);
            gridCopy[y][x].evolve(neighbors);
        }
    }

    // Update grid with evolved cells
    grid = gridCopy;
}
