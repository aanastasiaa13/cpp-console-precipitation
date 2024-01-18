#include "filter.h"
#include <cstring>
#include <iostream>
using namespace std;

precipitation** find_all_days_by_property(precipitation* array[], int size, int& result_size)
{
	precipitation** result = new precipitation*[size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (*array[i]->property == *" дождь")
		{
			result[result_size++] = array[i];
		}
	}

	return result;
}

precipitation** find_all_days_by_amount(precipitation* array[], int size, int& result_size)
{
	precipitation** result = new precipitation * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i]->amount < 1.5)
		{
			result[result_size++] = array[i];
		}
	}

	return result;
}