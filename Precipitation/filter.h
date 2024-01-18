#ifndef FILTER_H
#define FILTER_H

#include "precipitation.h"

precipitation** find_all_days_by_property(precipitation* array[], int size, int& result_size);

precipitation** find_all_days_by_amount(precipitation* array[], int size, int& result_size);

#endif
