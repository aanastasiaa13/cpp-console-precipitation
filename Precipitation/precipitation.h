#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include "constants.h"

struct precipitation
{
    int day;
    int month;
    double amount;
    char property[MAX_STRING_SIZE];
};

#endif