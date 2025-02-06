#pragma once
#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <algorithm>

struct PassportData {
    int series;
    int number;
    std::string fullName;
    int originalIndex; // номер строки входного файла

    bool operator<(const PassportData& other) const {
        if (series != other.series)
            return series < other.series;
        if (number != other.number)
            return number < other.number;
        return fullName > other.fullName; // Сортируем ФИО по убыванию
    }
};

void bubbleSort(PassportData data[], int size);
void mergeSort(PassportData data[], int left, int right);

#endif