#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::vector<int> splitAndConvert(const std::string& input) {
    std::istringstream stream(input);
    std::string segment;
    std::vector<int> numbers;

    while (std::getline(stream, segment, ' ')) {
        segment = trim(segment);

        if (!segment.empty()) {
            numbers.push_back(std::stoi(segment));
        }
    }
    return numbers;
}

int findTotalDistance() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file. \n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {

    }
    inputFile.close();
}

int main() {


    return 0;
}