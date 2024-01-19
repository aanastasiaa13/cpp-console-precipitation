#include "pch.h"
#include "CppUnitTest.h"
#include "D:\university\Основы программной инженерии\Лабораторная №1\cpp-console-precipitation\Precipitation\precipitation.h"
#include "D:\university\Основы программной инженерии\Лабораторная №1\cpp-console-precipitation\Precipitation\processing.h"
#include "D:\university\Основы программной инженерии\Лабораторная №1\cpp-console-precipitation\Precipitation\constants.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	precipitation* build_precipitation(int day, int month, double amount, char property[MAX_STRING_SIZE])
	{
		precipitation* precip = new precipitation;
		precip->day = day;
		precip->month = month;
		precip->amount = amount;
		strncpy_s(precip->property, property, MAX_STRING_SIZE);
		precip->property[MAX_STRING_SIZE - 1] = '\0';
		return precip;
	}

	void delete_precipitation(precipitation* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			precipitation* precip[3];
			precip[0] = build_precipitation(1, 1, 1.2, "дождь");
			precip[1] = build_precipitation(2, 1, 1.8, "мокрый снег");
			precip[2] = build_precipitation(3, 1, 2.2, "снег");
			Assert::AreEqual(5.2, process(precip, 3, 1));
			delete_precipitation(precip, 3);
		}
	};
}
