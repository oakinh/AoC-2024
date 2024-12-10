#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cmath>

std::pair<std::vector<int>, std::vector<int>> readAndSplit() {
    std::ifstream inputFile("day_one/input.txt");
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

    return {list1, list2};
}

int findTotalDistance(const std::vector<int>& list1, const std::vector<int>& list2) {
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int totalDistance = 0;

    for (int i = 0; i < list1.size(); i++) {
        int distance = std::abs(list1[i] - list2[i]);
        totalDistance += distance;
    }
    
    std::cout << "Total distance is " << totalDistance << std::endl;

    return totalDistance;
}

int calculateSimilarityScore(std::vector<int>left, std::vector<int>right) {
    // Inputs are sorted
    std::unordered_map<int, int> leftMap;
    std::unordered_map<int, int> rightMap;

    for (int i = 0; i < left.size(); i++) {
        leftMap[left[i]]++;
        rightMap[right[i]]++;
    }

    int similarityScore = 0;

    for (const auto& pair : leftMap) {
        int key = pair.first;

        if (rightMap.find(key) != rightMap.end()) {
            similarityScore += key * leftMap[key] * rightMap[key];
        }
    }

    std::cout << "Similarity Score: " << similarityScore << std::endl;

    return similarityScore;

    // std::cout << "Left map has: ";
    // for (const auto& pair : leftMap) {
    //     std::cout << "{" << pair.first << ": " << pair.second << "} ";
    // }
    // std::cout << std::endl;

    // // Print rightMap
    // std::cout << "Right map has: ";
    // for (const auto& pair : rightMap) {
    //     std::cout << "{" << pair.first << ": " << pair.second << "} ";
    // }
    // std::cout << std::endl;

}

int main() {
    auto [list1, list2] = readAndSplit();
    int totalDistance = findTotalDistance(list1, list2);
    calculateSimilarityScore(list1, list2);


    return 0;
}