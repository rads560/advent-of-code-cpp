#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> parseInput(std::string filename) {
    std::string line;
    std::ifstream input;
    std::vector<int> depths;
    int32_t depth;

    input.open(filename);
    while (std::getline(input, line)) {
        depth = atoi(line.c_str());
        depths.push_back(depth);
    }
    return depths;
}

int part_one(std::vector<int> depths) {
    int increasing = 0;
    for (int i = 1; i < depths.size(); i++){
        increasing += depths[i] > depths[i-1];
    }
    return increasing;
}

int part_two(std::vector<int> depths) {
    int increasing = 0;
    for (int i = 3; i < depths.size(); i++) {
        increasing += (depths[i] > depths[i - 3]);
    }
    return increasing;
}

int main() {
    std::vector<int> depths = parseInput("input.txt");
    // int increasing = part_one(depths);
    int increasing = part_two(depths);
    std::cout << "increasing depths: " << increasing << "\n";
    return 0;
}