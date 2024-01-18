#include "sort.h"
#include <cstring>
#include <iostream>
using namespace std;

int compare_by_amount(precipitation* prec1, precipitation* prec2) {
    return (prec1->amount < prec2->amount) ? -1 : ((prec1->amount > prec2->amount) ? 1 : 0);
}

int compare_by_property(precipitation* prec1, precipitation* prec2) {
    int typeComparison = std::strcmp(prec1->property, prec2->property);
    if (typeComparison != 0) {
        return typeComparison;
    }
    if (prec1->month != prec2->month) {
        return prec1->month - prec2->month;
    }
    return prec1->day - prec2->day;
}

void shaker_sort(precipitation** array, int size, int (*compare)(precipitation*, precipitation*)) {
    int left = 0, right = size - 1;
    while (left <= right) {
        for (int i = right; i > left; --i) {
            if (compare(array[i - 1], array[i]) > 0) {
                std::swap(array[i - 1], array[i]);
            }
        }
        ++left;

        for (int i = left; i < right; ++i) {
            if (compare(array[i], array[i + 1]) > 0) {
                std::swap(array[i], array[i + 1]);
            }
        }
        --right;
    }
}

void quick_sort(precipitation** array, int left, int right, int (*compare)(precipitation*, precipitation*)) {
    if (left < right) {
        int pivotIndex = left + (right - left) / 2;
        precipitation* precip = array[pivotIndex];
        int i = left, j = right;
        while (i <= j) {
            while (compare(array[i], precip) < 0) ++i;
            while (compare(array[j], precip) > 0) --j;
            if (i <= j) {
                std::swap(array[i], array[j]);
                ++i;
                --j;
            }
        }
        quick_sort(array, left, j, compare);
        quick_sort(array, i, right, compare);
    }
}