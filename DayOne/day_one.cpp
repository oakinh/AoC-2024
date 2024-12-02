#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

void findTotalDistance() {
    std::ifstream inputFile("DayOne/input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file. \n";
        // return 1;
    }

    std::vector<int> list1;
    std::vector<int> list2;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        int num1, num2;

        if (stream >> num1 >> num2) {
            list1.push_back(num1);
            list2.push_back(num2);
        } else {
            std::cerr << "Error: Invalid line format -> " << line << "\n";
        }
    }
    inputFile.close();

    std::cout << "List 1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "List 2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    findTotalDistance();

    return 0;
}