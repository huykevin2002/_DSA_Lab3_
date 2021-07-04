#include "Header.h"

void countingSort(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int* count = new int[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
}

unsigned long long countingSort_compare(int a[], int n)
{
	unsigned long long count_compare = 0;
	int max = a[0];
	for (int i = 1; ++count_compare && i < n; i++)
		if (++count_compare && a[i] > max)
			max = a[i];

	int* count = new int[max + 1];
	for (int i = 0; ++count_compare && i <= max; i++)
		count[i] = 0;

	for (int i = 0; ++count_compare && i < n; i++)
		count[a[i]]++;

	for (int i = 1; ++count_compare && i <= max; i++)
		count[i] += count[i - 1];

	int* temp = new int[n];
	for (int i = 0; ++count_compare && i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; ++count_compare && i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;

	return count_compare;
}

double countingSort_time(int a[], int n, unsigned long long& count_compare) {
	time_t start, end;
	start = time(NULL);
	count_compare = countingSort_compare(a, n);
	end = time(NULL);

	return difftime(end, start);
}

// source: https://nguyenvanhieu.vn/counting-sort/

//void insertionSort(int a[], int n)
//{
//    for (int i = 1; i < n; i++)
//    {
//        int k = i - 1;
//        int key = a[i];
//        while (a[k] > key && k >= 0)
//        {
//            a[k + 1] = a[k];
//            k--;
//        }
//        a[k + 1] = key;
//    }
//}
//
//void flashSort(int a[], int n)
//{
//    int minVal = a[0];
//    int max = 0;
//    int m = int(0.45 * n);
//    int* l = new int[m];
//    for (int i = 0; i < m; i++)
//        l[i] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (a[i] < minVal)
//            minVal = a[i];
//        if (a[i] > a[max])
//            max = i;
//    }
//    if (a[max] == minVal)
//        return;
//    double c1 = (double)(m - 1) / (a[max] - minVal);
//    for (int i = 0; i < n; i++)
//    {
//        int k = int(c1 * (a[i] - minVal));
//        ++l[k];
//    }
//    for (int i = 1; i < m; i++)
//        l[i] += l[i - 1];
//    HoanVi(a[max], a[0]);
//    int nmove = 0;
//    int j = 0;
//    int k = m - 1;
//    int t = 0;
//    int flash;
//    while (nmove < n - 1)
//    {
//        while (j > l[k] - 1)
//        {
//            j++;
//            k = int(c1 * (a[j] - minVal));
//        }
//        flash = a[j];
//        if (k < 0) break;
//        while (j != l[k])
//        {
//            k = int(c1 * (flash - minVal));
//            int hold = a[t = --l[k]];
//            a[t] = flash;
//            flash = hold;
//            ++nmove;
//        }
//    }
//    delete[] l;
//    insertionSort(a, n);
//}
//
//void insertionSort_compare(int a[], int n, int &count_compare)
//{
//    for (int i = 1; ++count_compare && i < n; i++)
//    {
//        int k = i - 1;
//        int key = a[i];
//        while (++count_compare && ++count_compare && a[k] > key && k >= 0)
//        {
//            a[k + 1] = a[k];
//            k--;
//        }
//        a[k + 1] = key;
//    }
//}
//
//int flashSort_compare(int a[], int n)
//{
//    int count_compare = 0;
//    int minVal = a[0];
//    int max = 0;
//    int m = int(0.45 * n);
//    int* l = new int[m];
//    for (int i = 0; ++count_compare && i < m; i++)
//        l[i] = 0;
//    for (int i = 1; ++count_compare && i < n; i++)
//    {
//        if (++count_compare && a[i] < minVal)
//            minVal = a[i];
//        if (++count_compare && a[i] > a[max])
//            max = i;
//    }
//    if (++count_compare && a[max] == minVal)
//        return count_compare;
//    double c1 = (double)(m - 1) / (a[max] - minVal);
//    for (int i = 0; ++count_compare && i < n; i++)
//    {
//        int k = int(c1 * (a[i] - minVal));
//        ++l[k];
//    }
//    for (int i = 1; ++count_compare && i < m; i++)
//        l[i] += l[i - 1];
//    HoanVi(a[max], a[0]);
//    int nmove = 0;
//    int j = 0;
//    int k = m - 1;
//    int t = 0;
//    int flash;
//    while (++count_compare && nmove < n - 1)
//    {
//        while (++count_compare && j > l[k] - 1)
//        {
//            j++;
//            k = int(c1 * (a[j] - minVal));
//        }
//        flash = a[j];
//        if (++count_compare && k < 0) break;
//        while (++count_compare && j != l[k])
//        {
//            k = int(c1 * (flash - minVal));
//            int hold = a[t = --l[k]];
//            a[t] = flash;
//            flash = hold;
//            ++nmove;
//        }
//    }
//    delete[] l;
//    insertionSort_compare(a, n, count_compare);
//
//    return count_compare;
//}
//
//double flashSort_time(int a[], int n) {
//    time_t start, end;
//
//    start = time(NULL);
//    flashSort(a, n);
//    end = time(NULL);
//
//    return difftime(end, start);
//}