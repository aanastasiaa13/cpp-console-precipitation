#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include "constants.h"

struct precipitation
{
    int day;
    int month;
    int amount;
    char prorepry[MAX_STRING_SIZE];
};

#endif