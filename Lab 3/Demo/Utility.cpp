#include "Header.h"

void OrderType(int order)
{
	switch (order)
	{
	case 0:cout << "Random"; break;
	case 1:cout << "Sorted"; break;
	case 2:cout << "Nearly Sorted"; break;
	case 3:cout << "Reverse"; break;
	}
}

void CopyArr(int* source, int* dest, int n)
{
	for (int i = 0; i < n; i++) {
		dest[i] = source[i];
	}
}

void GetData()
{
	int check[] = { 10000, 30000, 50000, 100000, 300000, 500000 };
	for (int i = 0; i < 4; i++)
	{
		cout << '\n'; OrderType(i);
		for (int size = 0; size < 6; size++) {
			int* a = new int[check[size]];
			int* b = new int[check[size]];
			GenerateData(a, check[size], i);
			CopyArr(a, b, check[size]);
			clock_t start, end;
			unsigned long long compare = 0;
			start = clock();
			// ham ko dem

			end = clock();
			// ham dem

			cout << "\n size: " << check[size] << "\ttime\t" << end - start << " ms \t\tcompare: " << compare;
			delete[]a;
			delete[]b;
		}
	}
}