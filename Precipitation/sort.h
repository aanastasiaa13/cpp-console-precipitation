#ifndef SORT_H
#define SORT_H

#include "precipitation.h"

int compare_by_amount(precipitation* prec1, precipitation* prec2);
int compare_by_property(precipitation* prec1, precipitation* prec2);
void shaker_sort(precipitation** array, int size, int (*compare)(precipitation*, precipitation*));
void quick_sort(precipitation** array, int left, int right, int (*compare)(precipitation*, precipitation*));

#endif
