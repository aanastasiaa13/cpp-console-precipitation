#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>


void read(const char* file_name, precipitation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            precipitation* item = new precipitation;
            file >> item->day;
            file >> item->month;
            file >> item->amount;
            file.getline(item->property, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}