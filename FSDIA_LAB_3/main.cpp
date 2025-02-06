#include <iostream>
#include <vector>
#include <chrono>
#include "sort.h"
#include "utils.h"

int main() {
    std::string inputFile = "input.txt";
    std::string bubbleOutputFile = "bubble_sorted.txt";
    std::string mergeOutputFile = "merge_sorted.txt";

    int n;
    std::cout << "Enter the number of lines to process (10 <= n <= 1000): ";
    std::cin >> n;

    if (n < 10 || n > 1000) {
        std::cerr << "Invalid input. n should be between 10 and 1000.\n";
        return 1;
    }

    std::vector<PassportData> data;
    readFile(inputFile, data, n);

    // Bubble Sort
    std::vector<PassportData> bubbleData = data;
    PassportData* bubbleArray = bubbleData.data();
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleArray, n);
    auto end = std::chrono::high_resolution_clock::now();
    long long bubbleDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    writeFile(bubbleOutputFile, bubbleData, bubbleDuration);

    std::cout << "Bubble sort stability: " << (isStable(data, bubbleData) ? "Stable" : "Unstable") << "\n";

    // Merge Sort
    std::vector<PassportData> mergeData = data;
    PassportData* mergeArray = mergeData.data();
    start = std::chrono::high_resolution_clock::now();
    mergeSort(mergeArray, 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    long long mergeDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    writeFile(mergeOutputFile, mergeData, mergeDuration);

    std::cout << "Merge sort stability: " << (isStable(data, mergeData) ? "Stable" : "Unstable") << "\n";

    // Compare sorting times
    compareSortingTimes(bubbleDuration, mergeDuration);

    std::cout << "Sorting completed. Results saved to output files.\n";
    return 0;
}
