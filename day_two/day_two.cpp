#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

enum class LevelProgression {
    Increasing,
    Decreasing,
};

bool isLineSafe(const std::vector<int>& values, std::size_t lineNumber, bool dampenerOn) {
    if (values.size() < 2) {
        return true;
    }

    LevelProgression prog;
    
    if (values[0] < values[1]) {
        prog = LevelProgression::Increasing;
    } else {
        prog = LevelProgression::Decreasing;
    }

    for (std::size_t i = 1; i < values.size(); ++i) {
        if (i > 1) {
            if ((prog == LevelProgression::Increasing && values[i-1] >= values[i]) ||
                (prog == LevelProgression::Decreasing && values[i-1] <= values[i])) {
                    if (dampenerOn) {
                        for (std::size_t j = 0; j < values.size(); j++) {
                                std::vector<int> newerValues = values;
                                newerValues.erase(newerValues.begin() + j);
                                bool safeFound = isLineSafe(newerValues, lineNumber, false);
                                if (safeFound) {
                                    return true;
                                }
                            }
                            return false;
                    } else {
                        std::cout << "Line " << lineNumber << " violates continuation rules." << std::endl;
                        return false;
                    }
                }
        }

        int diff = std::abs(values[i-1] - values[i]);
        if (diff < 1 || diff > 3) {
            if (dampenerOn) {
                    for (std::size_t j = 0; j < values.size(); j++) {
                        std::vector<int> newerValues = values;
                        newerValues.erase(newerValues.begin() + j);
                        bool safeFound = isLineSafe(newerValues, lineNumber, false);
                        if (safeFound) {
                            return true;
                        }
                    }
                    return false;
            } else {
                std::cout << "Line " << lineNumber << " has an invalid difference: " << diff << std::endl;
                return false;
            }

        }
    }
    return true;
}

int main() {
    std::ifstream inputFile("day_two/input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    
    std::string line;
    int safeCount = 0;
    int safeCountDampener = 0;
    int lineCount = 0;

    while (std::getline(inputFile, line)) {
        lineCount++;
        std::istringstream iss(line);
        std::vector<int> values;
        int value;

        while (iss >> value) {
            values.push_back(value);
        }
        
        if (isLineSafe(values, lineCount, false)) {
            safeCount++;
        }
        if (isLineSafe(values, lineCount, true)) {
            safeCountDampener++;
        }

    }

    std::cout << "Total safe count is: " << safeCount << std::endl;
    std::cout << "Total safe count with dampener " << safeCountDampener << std::endl;

    return 0;
}

