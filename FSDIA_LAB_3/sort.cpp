#include "sort.h"

void bubbleSort(PassportData data[], int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (data[i + 1] < data[i]) {
                std::swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void merge(PassportData data[], int left, int mid, int right) {
    std::vector<PassportData> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i] < data[j]) {
            temp.push_back(data[i++]);
        }
        else {
            temp.push_back(data[j++]);
        }
    }
    while (i <= mid) temp.push_back(data[i++]);
    while (j <= right) temp.push_back(data[j++]);

    for (int k = left; k <= right; ++k) {
        data[k] = temp[k - left];
    }
}

void mergeSort(PassportData data[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}