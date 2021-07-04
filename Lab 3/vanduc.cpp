#include"Header.h"
//Source:Data.Structures.and.Algorithms.Made.Easy
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
	for (int i = 0; i <= size; i++) {
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



//Source: https://www.geeksforgeeks.org/heap-sort
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
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void HeapSort(int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
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
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void AnotherHeapSort(int* arr, int n, unsigned long long& Count_compare) {
	for (int i = n / 2 - 1; ++Count_compare && i >= 0; i--) {
		AnotherHeapify(arr, n, i, Count_compare);
	}
	for (int i = n - 1; ++Count_compare && i >= 0; i--) {
		swap(arr[0], arr[i]);
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



//source: https://www.geeksforgeeks.org/radix-sort/
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

double BubbleSortTime(int* a, int n)
{
	clock_t start, end;
	start = clock();
	radixsort(a, n);
	end = clock();
	return difftime(end, start);
}
