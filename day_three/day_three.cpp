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
    std::regex patternWithToggle("mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\)");

    std::smatch match;
    int lineNumber = 0;

    int totalMul = 0;

    bool yesDo = true;

    while (std::getline(file, line)) {
        lineNumber++;

        auto begin = std::sregex_iterator(line.begin(), line.end(), patternWithToggle);
        auto end = std::sregex_iterator();

        if (begin == end) {
            std::cout << "No matches found" << std::endl;
        } else {
            for (std::sregex_iterator i = begin; i != end; i++) {
                std::smatch match = *i;
                if (match[0].str() == "do()") {
                    std::cout << "Do found, setting yesDo to true, before it was: " << yesDo << std::endl;
                    yesDo = true;
                } else if (match[0].str() == "don't()") {
                    std::cout << "Don't found, setting yesDo to false, before it was: " << yesDo << std::endl;
                    yesDo = false;
                } else if (match.size() == 3 && yesDo) {
                    int firstNum = std::stoi(match[1].str());
                    int secondNum = std::stoi(match[2].str());
                    totalMul += (firstNum * secondNum); 
                } else {
                    std::cout << "Mul encountered, yesDo is false, skipping: " << match[0] << std::endl;
                }
            }
        }
    }

    std::cout << "Total score after multiplication is: " << totalMul << std::endl;

    return 0;
}