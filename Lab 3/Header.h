#ifndef Header
#define Header
#include<iostream>
#include<time.h>
#include <fstream>
#include <cmath>
using namespace std;

//-------------------------------------------------

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


// Insertion Sort


// Bubble Sort
//https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/
void BubbleSort(int* a, int n);
void BubbleSortCompare(int* a, int n, unsigned long long& compare);

// Shaker Sort
// https://www.stdio.vn/giai-thuat-lap-trinh/bubble-sort-va-shaker-sort-01Si3U
void ShakerSort(int* a, int n);
void ShakerSortCompare(int* a, int n, unsigned long long& compare);

// Shell Sort


// Heap Sort


// Merge Sort


// Quick Sort
// https://stackoverflow.com/questions/33837737/quick-sort-middle-pivot-implementation-strange-behaviour
void quickSortMiddle(int* a, int left, int right);
void quickSortMiddleCompare(int* a, int left, int right, unsigned long long& compare);

// Counting Sort


// Radix Sort


// Flash sort
#endif
