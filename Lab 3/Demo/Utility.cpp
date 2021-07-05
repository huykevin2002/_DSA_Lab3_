#include "Header.h"

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void OrderType(int order)
{
	switch (order)
	{
	case 0:cout << "RANDOMIZE\n"; break;
	case 1:cout << "SORTED\n"; break;
	case 2:cout << "REVERSE SORTED\n"; break;
	case 3:cout << "NEARLY SORTED\n"; break;
	default: break;
	}
}

void GetSort(int sort, int* a, int* b, int* c, int n, double& time, unsigned long long& compare)
{
	switch (sort)
	{
	case 1:
		cout << "Selection Sort \n";
		time = selection_sort_time(a, n);
		compare = selection_sort_compare(b, n);
		break;
	case 2:
		cout << "Insertion Sort \n";
		time = insert_sort_time(a, n);
		compare = insert_sort_compare(b, n);
		break;
	case 3:
		cout << "Bubble Sort \n";
		time = BubbleSortTime(a, n);
		compare = BubbleSortCompare(b, n);
		break;
	case 4:
		cout << "Shaker Sort \n";
		time = ShakerSortTime(a, n);
		compare = ShakerSortCompare(b, n);
		break;
	case 5:
		cout << "Shell Sort \n";
		time = shell_sort_time(a, n);
		compare = shell_sort_compare(b, n);
		break;
	case 6:
		cout << "Heap Sort \n";
		time = HeapSortTime(a, n);
		compare = HeapSortCompare(b, n);
		break;
	case 7:
		cout << "Merge Sort \n";	
		time = MergeSortTime(a, c, n);
		compare = MergeSort_Compare(b, c, n);
		break;
	case 8:
		cout << "Quick Sort \n";
		time = QuickSortTime(a, 0, n - 1);
		compare = QuickSortCompare(b, 0, n - 1);
		break;
	case 9:
		cout << "Counting Sort \n";
		time = countingSort_time(a, n);
		compare = countingSort_compare(b, n);
		break;
	case 10:
		cout << "Radix Sort \n";
		time = RadixTime(a, n);
		compare = RadixCompare(b, n);
		break;
	case 11:
		cout << "Flash Sort \n";
		time = flashSort_time(a, n);
		compare = flashSort_compare(b, n);
		break;
	default:
		break;
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
	cout << "Choose order and size: \n";
	int order, n;
	cout << "0. Randomized\n1. Sorted\n2. Reverse Sorted\n3. Nearly Sorted\n";
	cin >> order >> n;
	cout << '\n'; OrderType(order);
	int* a, * b, *c;
	for (int i = 1; i <= 11; i++)
	{
		a = new int[n];
		b = new int[n];
		c = new int[n];
		GenerateData(a, n, order);
		CopyArr(a, b, n);
		unsigned long long compare;
		double time;
		GetSort(i, a, b, c, n, time, compare);
		cout << "Time:\t " << time << " ms\t Comparisions: " << compare << "\n\n";
		delete[]a;
		delete[]b;
		delete[]c;
	}
}