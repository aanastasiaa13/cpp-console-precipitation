#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

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