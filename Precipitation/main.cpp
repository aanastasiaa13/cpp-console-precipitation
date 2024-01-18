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
    cout << "������������ ������ �1. GIT\n";
    cout << "������� �3. ������\n";
    cout << "�����: ��������� �������\n\n";
    precipitation* precip[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", precip, size);
        cout << "***** ������ *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ���������� �� ������� **********/
            cout << "���������� �� �������........: ";
            // ����� ���
            cout << precip[i]->day << ".";
            // ����� ������
            cout << precip[i]->month << " ";
            // ����� ����������
            cout << precip[i]->amount << " ";
            // ����� ��������������
            cout << precip[i]->property;
            cout << '\n';
            cout << '\n';
        }

        int filter;
        cout << "������� ����������:\n";
        cout << "1) ����� ��� ���, � ������� ��� �����.\n";
        cout << "2) ����� ��� ���, � ������� ����� ������� ��� ������ 1,5.\n";
        cout << "�������� ������ ����������: ";
        cin >> filter;
        switch (filter)
        {
        case 1:
        {
            int new_size = 0;
            precipitation** all_days_by_property = find_all_days_by_property(precip, size, new_size);
            for (int i = 0; i < new_size; i++)
            {
                cout << "����: " << all_days_by_property[i]->day << " �����: " << all_days_by_property[i]->month << "\n";
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
        cout << "������ ����������:\n";
        cout << "1) ��������� ���������� (Shaker sort).\n";
        cout << "2) ������� ���������� (Quick sort).\n";
        cout << "�������� ����� ����������: ";
        cin >> sort_method;
        cout << "���������� ������:\n";
        cout << "�������� ����������:\n";
        cout << "1) �� ����������� ���������� �������.\n";
        cout << "2) �� ����������� ��������������, � � ������ ����� �������������� �� ����������� ������ ������, � � ������ ������ ������ �� ����������� ������ ���\n";
        cout << "�������� �������� ����������: ";
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
        cout << "��������������� ������:" << std::endl;
        for (int i = 0; i < size; ++i) {
            cout << "����: " << precip[i]->day << " �����: " << precip[i]->month
                << " ������: " << precip[i]->amount << " ��������������: " << precip[i]->property << endl;
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