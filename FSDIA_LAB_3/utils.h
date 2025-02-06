#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "sort.h"

void readFile(const std::string& filename, std::vector<PassportData>& data, int n);
void writeFile(const std::string& filename, const std::vector<PassportData>& data, long long duration);
bool isStable(const std::vector<PassportData>& original, const std::vector<PassportData>& sorted);
void compareSortingTimes(long long bubbleDuration, long long mergeDuration);

#endif // UTILS_H
