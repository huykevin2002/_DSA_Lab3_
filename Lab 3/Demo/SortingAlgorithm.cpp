#include "Header.h"

// 1. SELECTION SORT
void selection_sort(int*& arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		HoanVi(arr[i], arr[index]);
	}
}
unsigned long long selection_sort_compare(int*& arr, int n)
{
	unsigned long long compare = 0;
	for (int i = 0; ++compare && i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; ++compare && j < n; j++)
		{
			if (++compare && arr[index] > arr[j])
			{
				index = j;
			}
		}
		HoanVi(arr[i], arr[index]);
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



// 2. INSERTION SORT
void insert_sort(int*& arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int a = arr[i];
		while (j >= 0 && arr[j] > a)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = a;
	}
}
unsigned long long insert_sort_compare(int*& arr, int n)
{
	unsigned long long compare = 0;
	for (int i = 1; ++compare && i < n; i++)
	{
		int j = i - 1;
		int a = arr[i];
		while (++compare && j >= 0 && ++compare && arr[j] > a)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = a;
	}
	return compare;
}
double  insert_sort_time(int* a, int n)
{
	clock_t start, end;
	start = clock();
	insert_sort(a, n);
	end = clock();
	return difftime(end, start);
}



// 3. BUBBLE SORT
void BubbleSort(int* a, int n)
{
	for (int j = n; j > 0; j--)
	{
		bool isHoanVi = false;
		for (int i = 0; i < j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				isHoanVi = true;
			}
		}
		if (!isHoanVi)
			break;
	}
}
void BubbleSort(int* a, int n, unsigned long long& compare)
{
	for (int j = n; ++compare && j > 0; j--)
	{
		bool isHoanVi = false;
		for (int i = 0; ++compare && i < j - 1; i++)
		{
			if (++compare && a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				isHoanVi = true;
			}
		}
		if (++compare && !isHoanVi)
			break;
	}
}
unsigned long long BubbleSortCompare(int* a, int n)
{
	unsigned long long compare = 0;
	BubbleSort(a, n, compare);
	return compare;
}
double BubbleSortTime(int* a, int n)
{
	clock_t start, end;
	start = clock();
	BubbleSort(a, n);
	end = clock();
	return difftime(end, start);
}



// 4. SHAKER SORT
void ShakerSort(int* a, int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
void ShakerSort(int* a, int n, unsigned long long& compare)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++compare&& Left < Right)
	{
		for (int i = Left; ++compare && i < Right; i++)
		{
			if (++compare && a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++compare && i > Left; i--)
		{
			if (++compare && a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
unsigned long long ShakerSortCompare(int* a, int n)
{
	unsigned long long compare = 0;
	ShakerSort(a, n, compare);
	return compare;
}
double ShakerSortTime(int* a, int n)
{
	clock_t start, end;
	start = clock();
	ShakerSort(a, n);
	end = clock();
	return difftime(end, start);
}



// 5. SHELL SORT
void shell_Sort(int*& a, int n)        
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
unsigned long long shell_sort_compare(int*& a, int n)
{
	unsigned long long compare = 0;
	int interval, i, j, temp;
	for (interval = n / 2; ++compare && interval > 0; interval /= 2) {
		for (i = interval; ++compare && i < n; i++) {
			temp = a[i];
			for (j = i; ++compare && j >= interval && ++compare && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
	return compare;
}
double  shell_sort_time(int* a, int n)
{
	clock_t start, end;
	start = clock();
	shell_Sort(a, n);
	end = clock();
	return difftime(end, start);
}



// 6. HEAP SORT
void Heapify(int* arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && arr[left]>arr[largest]) {
		largest = left;
	}
	if (right<n && arr[right]>arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		HoanVi(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void HeapSort(int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		HoanVi(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}
void AnotherHeapify(int arr[], int n, int i, unsigned long long& Count_compare) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if ((++Count_compare && left < n) && (++Count_compare && arr[left] > arr[largest])) {
		largest = left;
	}
	if ((++Count_compare && right < n) && (++Count_compare && arr[right] > arr[largest])) {
		largest = right;
	}
	if (++Count_compare && largest != i) {
		HoanVi(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void AnotherHeapSort(int* arr, int n, unsigned long long& Count_compare) {
	for (int i = n / 2 - 1; ++Count_compare && i >= 0; i--) {
		AnotherHeapify(arr, n, i, Count_compare);
	}
	for (int i = n - 1; ++Count_compare && i >= 0; i--) {
		HoanVi(arr[0], arr[i]);
		AnotherHeapify(arr, i, 0, Count_compare);
	}
}
unsigned long long HeapSortCompare(int* a, int n)
{
	unsigned long long compare = 0;
	AnotherHeapSort(a, n, compare);
	return compare;
}
double HeapSortTime(int* a, int n)
{
	clock_t start, end;
	start = clock();
	HeapSort(a, n);
	end = clock();
	return difftime(end, start);
}



// 7. MERGE SORT
void Merge(int* a, int* Tmp, int left, int mid, int right) {
	int i, left_end, cur;
	left_end = mid - 1;
	cur = left;
	int size;
	size = right - left + 1;
	while (left <= left_end && mid <= right) {
		if (a[left] <= a[mid]) {
			Tmp[cur] = a[left];
			cur = cur + 1;
			left = left + 1;
		}
		else {
			Tmp[cur] = a[mid];
			cur = cur + 1;
			mid = mid + 1;

		}
	}
	while (left <= left_end) {
		Tmp[cur] = a[left];
		cur = cur + 1;
		left = left + 1;
	}
	while (mid <= right) {
		Tmp[cur] = a[mid];
		cur = cur + 1;
		mid = mid + 1;
	}
	for (int i = 0; i < size; i++) {
		a[right] = Tmp[right];
		right = right - 1;
	}
}
void MergeSort(int* a, int* Tmp, int left, int right) {
	int mid;
	if (right > left) {
		mid = (right + left) / 2;
		MergeSort(a, Tmp, left, mid);
		MergeSort(a, Tmp, mid + 1, right);
		Merge(a, Tmp, left, mid + 1, right);
	}
}
void AnotherMerge(int* a, int* Tmp, int left, int mid, int right, unsigned long long& Count_compare) {

	int i, left_end, cur;
	left_end = mid - 1;
	cur = left;
	int size;
	size = right - left + 1;
	while ((++Count_compare && left <= left_end) && (++Count_compare && mid <= right)) {
		if (++Count_compare && a[left] <= a[mid]) {
			Tmp[cur] = a[left];
			cur = cur + 1;
			left = left + 1;
		}
		else {
			Tmp[cur] = a[mid];
			cur = cur + 1;
			mid = mid + 1;

		}
	}
	while (++Count_compare && left <= left_end) {
		Tmp[cur] = a[left];
		cur = cur + 1;
		left = left + 1;
	}
	while (++Count_compare && mid <= right) {
		Tmp[cur] = a[mid];
		cur = cur + 1;
		mid = mid + 1;
	}
	for (int i = 0; ++Count_compare && i <= size; i++) {
		a[right] = Tmp[right];
		right = right - 1;
	}

}
void AnotherMergeSort(int* a, int* Tmp, int left, int right, unsigned long long& Count_compare) {
	int mid;
	if (++Count_compare && right > left) {
		mid = (right + left) / 2;
		AnotherMergeSort(a, Tmp, left, mid, Count_compare);
		AnotherMergeSort(a, Tmp, mid + 1, right, Count_compare);
		AnotherMerge(a, Tmp, left, mid + 1, right, Count_compare);
	}

}
unsigned long long MergeSort_Compare(int* a, int* Tmp, int n) {
	unsigned long long compare = 0;
	AnotherMergeSort(a, Tmp, 0, n - 1, compare);
	return compare;
}
double MergeSortTime(int* a, int* Tmp, int n) {
	clock_t start, end;
	start = clock();
	MergeSort(a, Tmp, 0, n - 1);
	end = clock();
	return difftime(end, start);
}



// 8. QUICK SORT
void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;
	int pivot = a[left + (right - left) / 2];
	int leftI = left - 1;
	int rightI = right + 1;
	while (1)
	{
		while (a[++leftI] < pivot);
		while (a[--rightI] > pivot);
		if (leftI >= rightI)
			break;
		HoanVi(a[leftI], a[rightI]);
	}
	QuickSort(a, left, rightI);
	QuickSort(a, rightI + 1, right);
}
void QuickSort(int* a, int left, int right, unsigned long long& compare)
{
	if (++compare && left >= right) return;
	int pivot = a[left + (right - left) / 2];
	int leftI = left - 1;
	int rightI = right + 1;
	while (1)
	{
		while (++compare && a[++leftI] < pivot);
		while (++compare && a[--rightI] > pivot);
		if (++compare && leftI >= rightI)
			break;
		HoanVi(a[leftI], a[rightI]);
	}
	QuickSort(a, left, rightI);
	QuickSort(a, rightI + 1, right);
}
unsigned long long QuickSortCompare(int* a, int left, int right)
{
	unsigned long long compare = 0;
	QuickSort(a, left, right, compare);
	return compare;
}
double QuickSortTime(int* a, int left, int right)
{
	clock_t start, end;
	start = clock();
	QuickSort(a, left, right);
	end = clock();
	return difftime(end, start);
}



// 9. COUNTING SORT
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
double countingSort_time(int a[], int n) {
	clock_t start, end;

	start = clock();
	countingSort(a, n);
	end = clock();

	return end - start;
}



// 10. RADIX SORT
int Getmax(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void countSort(int* arr, int n, int exp) {
	int* output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixsort(int* arr, int n)
{

	int m = Getmax(arr, n);


	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
int AnotherGetmax(int arr[], int n, unsigned long long& Count_compare) {
	int max = arr[0];
	for (int i = 0; ++Count_compare && i < n; i++) {
		if (++Count_compare && arr[i] > max)
			max = arr[i];
	}
	return max;
}
void AnotherCountSort(int arr[], int n, int exp, unsigned long long& Count_compare) {
	int* output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; ++Count_compare && i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; ++Count_compare && i < 10; i++)
		count[i] += count[i - 1];


	for (i = n - 1; ++Count_compare && i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (i = 0; ++Count_compare && i < n; i++)
		arr[i] = output[i];
}
void AnotherradixSort(int arr[], int n, unsigned long long& Count_compare) {
	int m = AnotherGetmax(arr, n, Count_compare);


	for (int exp = 1; ++Count_compare && m / exp > 0; exp *= 10)
		AnotherCountSort(arr, n, exp, Count_compare);

}//
unsigned long long RadixCompare(int* a, int n)
{
	unsigned long long compare = 0;
	AnotherradixSort(a, n, compare);
	return compare;
}
double RadixTime(int* a, int n)
{
	clock_t start, end;
	start = clock();
	radixsort(a, n);
	end = clock();
	return difftime(end, start);
}



// 11. FLASH SORT
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
void flashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}
void insertionSort_compare(int a[], int n, unsigned long long& count_compare)
{
	for (int i = 1; ++count_compare && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (++count_compare && ++count_compare && a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}
unsigned long long flashSort_compare(int a[], int n)
{
	unsigned long long count_compare = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++count_compare && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] < minVal)
			minVal = a[i];
		if (++count_compare && a[i] > a[max])
			max = i;
	}
	if (++count_compare && a[max] == minVal)
		return count_compare;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++count_compare && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_compare && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_compare && nmove < n - 1)
	{
		while (++count_compare && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort_compare(a, n, count_compare);

	return count_compare;
}
double flashSort_time(int a[], int n) {
	clock_t start, end;

	start = clock();
	flashSort(a, n);
	end = clock();

	return end - start;
}



