#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №1. GIT\n";
    cout << "Вариант №3. Осадки\n";
    cout << "Автор: Анастасия Аравина\n\n";
    precipitation* precip[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", precip, size);
        cout << "***** Осадки *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод информации об осадках **********/
            cout << "Информация об осадках........: ";
            // вывод дня
            cout << precip[i]->day << ".";
            // вывод месяца
            cout << precip[i]->month << " ";
            // вывод количества
            cout << precip[i]->amount << " ";
            // вывод характеристики
            cout << precip[i]->property;
            cout << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete precip[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}