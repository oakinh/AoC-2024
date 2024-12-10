#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <utility>

bool checkAllDirections(const std::vector<std::string>& encryptedInput, std::pair<int, int> xpos) {
    std::array<std::pair<int, int>, 8> directions = {
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1},    // Up, Down, Left, Right
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}   // Diagonals
    };
    std::string mas = "MAS";

    for (size_t i = 0; i < mas.size(); ++i) {

    }


}

int main() {
    std::ifstream inputFile("day_four/input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file" << std::endl;
        return 1;
    }

    std::vector<std::string> encryptedInput;

    int xmasCount = 0;

    while (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);
        encryptedInput.push_back(line);
    }

    for (size_t i = 0; i < encryptedInput.size(); ++i) {
        for (size_t j = 0; j < encryptedInput[i].size(); ++j) {
           if (encryptedInput[i][j] == 'X') {

           }
        }
    }
}