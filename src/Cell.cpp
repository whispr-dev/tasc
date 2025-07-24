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
