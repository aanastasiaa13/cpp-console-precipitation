#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"


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
                cout << "День: " << all_days_by_property[i]->day << " Месяц: " << all_days_by_property[i]->month << "\n";
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

        int sort_criteria;
        int sort_method;
        cout << "Методы сортировки:\n";
        cout << "1) Шейкерная сортировки (Shaker sort).\n";
        cout << "2) Быстрая сортировка (Quick sort).\n";
        cout << "Выберите метод сортировки: ";
        cin >> sort_method;
        cout << "Сортировка данных:\n";
        cout << "Критерии сортировки:\n";
        cout << "1) По возрастанию количества осадков.\n";
        cout << "2) По возрастанию характеристики, а в рамках одной характеристики по возрастанию номера месяца, а в рамках одного месяца по возрастанию номера дня\n";
        cout << "Выберите критерий сортировки: ";
        cin >> sort_criteria;
        switch (sort_method)
        {
        case 1: 
        {
            shaker_sort(precip, size, (sort_criteria == 1) ? compare_by_amount : compare_by_property);
        }
        break;
        case 2: 
        {
            quick_sort(precip, 0, size - 1, (sort_criteria == 1) ? compare_by_amount : compare_by_property);
        }
        break;
        default:
            throw " ";
        }
        cout << "Отсортированные данные:" << std::endl;
        for (int i = 0; i < size; ++i) {
            cout << "День: " << precip[i]->day << " Месяц: " << precip[i]->month
                << " Осадки: " << precip[i]->amount << " Характеристика: " << precip[i]->property << endl;
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