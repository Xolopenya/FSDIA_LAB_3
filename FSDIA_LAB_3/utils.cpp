#include "utils.h"
#include <fstream>
#include <iostream>

void readFile(const std::string& filename, std::vector<PassportData>& data, int n) {
    std::ifstream file(filename);
    std::string line;
    for (int i = 0; i < n && std::getline(file, line); ++i) {
        PassportData entry;
        char nameBuffer[100];
        sscanf_s(line.c_str(), "%d %d %99[^\n]", &entry.series, &entry.number, nameBuffer, (unsigned)_countof(nameBuffer));
        entry.fullName = std::string(nameBuffer);
        entry.originalIndex = i + 1;
        data.push_back(entry);
    }
    file.close();
}

void writeFile(const std::string& filename, const std::vector<PassportData>& data, long long duration) {
    std::ofstream file(filename);
    for (const auto& entry : data) {
        file << entry.series << " " << entry.number << " " << entry.fullName << " " << entry.originalIndex << "\n";
    }
    file << "Time taken: " << duration << " ms\n";
    file.close();
}

bool isStable(const std::vector<PassportData>& original, const std::vector<PassportData>& sorted) {
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        if (sorted[i].series == sorted[i + 1].series &&
            sorted[i].number == sorted[i + 1].number &&
            sorted[i].fullName == sorted[i + 1].fullName &&
            sorted[i].originalIndex > sorted[i + 1].originalIndex) {
            return false;
        }
    }
    return true;
}

void compareSortingTimes(long long bubbleDuration, long long mergeDuration) {
    std::cout << "\n--- Comparison of Sorting Times ---\n";
    std::cout << "Bubble Sort Time: " << bubbleDuration << " ms\n";
    std::cout << "Merge Sort Time: " << mergeDuration << " ms\n";
    if (bubbleDuration < mergeDuration) {
        std::cout << "Bubble sort is faster in this case.\n";
    }
    else if (bubbleDuration > mergeDuration) {
        std::cout << "Merge sort is faster in this case.\n";
    }
    else {
        std::cout << "Both sorting algorithms took the same time.\n";
    }
}
