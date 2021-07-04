#ifndef Header
#define Header
#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

//-------------------------------------------------

template <class T>
void HoanVi(T& a, T& b);

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n);
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n);
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//-------------------------------------------------
// Help
void Swap(int& a, int& b);
void OrderType(int order);
void CopyArr(int* source, int* dest, int n);
void GetData();

//-------------------------------------------------
// Sort
// Selection Sort
void selection_sort(int*& arr, int n);
unsigned long long selection_sort_compare(int*& arr, int n);
double  selection_sort_time(int* a, int n);

// Insertion Sort
void insert_sort(int*& arr, int n);
unsigned long long insert_sort_compare(int*& arr, int n);
double  insert_sort_time(int* a, int n);

// Bubble Sort
//https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/
void BubbleSort(int* a, int n);
void BubbleSort(int* a, int n, unsigned long long& compare);
double BubbleSortTime(int* a, int n);
unsigned long long BubbleSortCompare(int* a, int n);

// Shaker Sort
// https://www.stdio.vn/giai-thuat-lap-trinh/bubble-sort-va-shaker-sort-01Si3U
void ShakerSort(int* a, int n);
void ShakerSort(int* a, int n, unsigned long long& compare);
double ShakerSortTime(int* a, int n);
unsigned long long ShakerSortCompare(int* a, int n);

// Shell Sort
void shell_Sort(int*& a, int n);
unsigned long long shell_sort_compare(int*& a, int n);
double  shell_sort_time(int* a, int n);

// Heap Sort
//Source: https://www.geeksforgeeks.org/heap-sort
void Heapify(int* arr, int n, int i);
void HeapSort(int* arr, int n);
void AnotherHeapify(int arr[], int n, int i, unsigned long long& Count_compare);
void AnotherHeapSort(int* arr, int n, unsigned long long& Count_compare);
unsigned long long HeapSortCompare(int* a, int n);
double HeapSortTime(int* a, int n);

// Merge Sort
//Source:Data.Structures.and.Algorithms.Made.Easy
void Merge(int* a, int* Tmp, int left, int mid, int right);
void MergeSort(int* a, int* Tmp, int left, int right);
void AnotherMerge(int* a, int* Tmp, int left, int mid, int right, unsigned long long& Count_compare);
void AnotherMergeSort(int* a, int* Tmp, int left, int right, unsigned long long& Count_compare);
unsigned long long MergeSort_Compare(int* a, int* Tmp, int n);
double MergeSortTime(int* a, int* Tmp, int n);

// Quick Sort
// https://stackoverflow.com/questions/33837737/quick-sort-middle-pivot-implementation-strange-behaviour
void QuickSort(int* a, int left, int right);
void QuickSort(int* a, int left, int right, unsigned long long& compare);
double QuickSortTime(int* a, int left, int right);
unsigned long long QuickSortCompare(int* a, int left, int right);

// Counting Sort
// source: https://github.com/HaiDuc0147/sortingAlgorithm/tree/main/reportSort
void countingSort(int a[], int n);
unsigned long long countingSort_compare(int a[], int n);
double countingSort_time(int a[], int n);

// Radix Sort
//source: https://www.geeksforgeeks.org/radix-sort/
int Getmax(int* arr, int n);
void countSort(int* arr, int n, int exp);
void radixsort(int* arr, int n);
int AnotherGetmax(int arr[], int n, unsigned long long& Count_compare);
void AnotherCountSort(int arr[], int n, int exp, unsigned long long& Count_compare);
void AnotherradixSort(int arr[], int n, unsigned long long& Count_compare);
unsigned long long RadixCompare(int* a, int n);
double RadixTime(int* a, int n);
//

// Flash sort
// source: https://github.com/HaiDuc0147/sortingAlgorithm/tree/main/reportSort
void flashSort(int a[], int n);
unsigned long long flashSort_compare(int a[], int n);
double flashSort_time(int a[], int n);

// MainArgument
int determineCommand(int argc, char* argv[]);
void Command1(char* argv[]);
void Command2(char* argv[]);
void Command3(char* argv[]);
void Command4(char* argv[]);
void Command5(char* argv[]);
#endif
