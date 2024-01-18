#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"


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

        int filter;
        cout << "Способы фильтрации:\n";
        cout << "1) Найти все дни, в которые шёл дождь.\n";
        cout << "2) Найти все дни, в которые объём осадков был меньше 1,5.\n";
        cout << "Выберите способ фильтрации: ";
        cin >> filter;
        switch (filter)
        {
        case 1:
        {
            int new_size = 0;
            precipitation** all_days_by_property = find_all_days_by_property(precip, size, new_size);
            for (int i = 0; i < new_size; i++)
            {
                cout << all_days_by_property[i]->day << "." << all_days_by_property[i]->month << "\n";
            }
            delete all_days_by_property;
        }
        break;
        case 2:
        {
            int new_size1 = 0;
            precipitation** all_days_by_amount = find_all_days_by_amount(precip, size, new_size1);
            for (int i = 0; i < new_size1; i++)
            {
                cout << all_days_by_amount[i]->day << "." << all_days_by_amount[i]->month << "\n";
            }
            delete all_days_by_amount;
        }
        break;
        default:
                throw " ";
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