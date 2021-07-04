#include<iostream>
#include<time.h>
using namespace std;
void selection_sort(int*& arr,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
 }
void insert_sort(int*& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		int a = arr[i];
		while (j >= 0 && arr[j] > a)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[0] = a;
	}
}
void shell_Sort(int*& a, int n)        //source code:https://codelearn.io/learning/data-structure-and-algorithms/856660
{
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}
unsigned long long selection_sort_compare(int*& arr, int n )
{
	unsigned long long compare = 0;
	for (int i = 0;++compare&& i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; ++compare && j < n; j++)
		{
			if (++compare && arr[index] > arr[j])
			{
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
	return compare;
}
unsigned long long insert_sort_compare(int*& arr, int n)
{
	unsigned long long compare = 0;
	for (int i = 0; ++compare && i < n; i++)
	{
		int j = i - 1;
		int a = arr[i];
		while (compare+=2 &&j >= 0 && arr[j] > a)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[0] = a;
	}
	return compare;
}
unsigned long long shell_sort_compare(int*& a, int n)
{
	unsigned long long compare = 0;
	int interval, i, j, temp;
	for (interval = n / 2; ++compare && interval > 0; interval /= 2) {
		for (i = interval; ++compare && i < n; i++) {
			temp = a[i];
			for (j = i; compare+=2 && j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
	return compare;
}
double  selection_sort_time(int* a, int n)
{
	clock_t start, end;
	start = clock();
	selection_sort(a, n);
	end = clock();
	return difftime(end, start);
}
double  insert_sort_time(int* a, int n)
{
	clock_t start, end;
	start = clock();
	insert_sort(a, n);
	end = clock();
	return difftime(end, start);
}
double  shell_sort_time(int* a, int n)
{
	clock_t start, end;
	start = clock();
	shell_sort(a, n);
	end = clock();
	return difftime(end, start);
}


