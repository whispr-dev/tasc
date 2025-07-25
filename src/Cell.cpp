#include "Cell.h"
#include <map>
#include <algorithm>

Cell::Cell() : tag("default") {}

void Cell::triggerOperation(const std::string& op) {
    if (op == "add") stack.add();
    else if (op == "sub") stack.sub();
    else if (op == "mul") stack.mul();
    else if (op == "div") stack.div();
    // Add other operations as needed
}

// Evolution logic (simple dominant-tag inheritance)
void Cell::evolve(const std::vector<Cell*>& neighbors) {
    std::map<std::string, int> tagCount;

    // Count the occurrences of each neighbor tag
    for (auto neighbor : neighbors) {
        tagCount[neighbor->tag]++;
    }

    // Find the most frequent tag among neighbors
    auto dominant_tag = std::max_element(
        tagCount.begin(), tagCount.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second < b.second;
        }
    );

    // Adopt the dominant tag if it exists and is different
    if (dominant_tag != tagCount.end() && dominant_tag->first != this->tag) {
        this->tag = dominant_tag->first;
    }
}

void Cell::evolve(const std::vector<Cell*>& neighbors) {
    // Simple demo: inherit most frequent neighbor tag
    std::map<std::string, int> tagCount;
    for (auto neighbor : neighbors)
        tagCount[neighbor->tag]++;

    auto dominant_tag = std::max_element(
        tagCount.begin(), tagCount.end(),
        [](auto& a, auto& b){ return a.second < b.second; }
    );

    if (dominant_tag != tagCount.end())
        tag = dominant_tag->first;
}

void Cell::applySelfModification(const std::string& modCommand) {
    if (modCommand == "set_add_tag")
        tag = "add";
    else if (modCommand == "set_mul_tag")
        tag = "mul";
    // ...other commands
}
