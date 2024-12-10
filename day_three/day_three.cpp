#include <string>
#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("day_three/input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern("mul\\((\\d+),(\\d+)\\)");

    std::smatch match;
    int lineNumber = 0;

    int totalMul = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        // std::cout << "Line " << lineNumber << ": " << line << std::endl;

        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();

        if (begin == end) {
            std::cout << "No matches found" << std::endl;
        } else {
            for (std::sregex_iterator i = begin; i != end; i++) {
                std::smatch match = *i;
                int firstNum = std::stoi(match[1].str());
                int secondNum = std::stoi(match[2].str());
                totalMul += (firstNum * secondNum);
            }
        }
    }

    std::cout << "Total score after multiplication is: " << totalMul << std::endl;

    return 0;
}