#include "Header.h"

void countingSort(int input[], int n)
{
    int output[n]; // The output will have sorted input array
    int max = input[0];
    int min = input[0];
 
    int i;
    for(i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i]; // Maximum value in array
        else if(input[i] < min)
            min = input[i]; // Minimum value in array
    }
 
    int k = max - min + 1; // Size of count array
 
    int count_array[k]; // Create a count_array to store count of each individual input value
    for(i=0; i<k; i++)
        count_array[i]=0;
 
    for(i = 0; i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value
 
    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for(i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];
 
    // Populate output array using count_array and input array
    for(i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }
 
    for(i = 0; i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values
 
}

int countingSort_compare(int input[], int n)
{
    int count_compare = 0;
    int output[n]; // The output will have sorted input array
    int max = input[0];
    int min = input[0];

    int i;
    for (i = 1; ++count_compare && i < n; i++)
    {
        if (++count_compare && input[i] > max)
            max = input[i]; // Maximum value in array
        else if (++count_compare && input[i] < min)
            min = input[i]; // Minimum value in array
    }

    int k = max - min + 1; // Size of count array

    int count_array[k]; // Create a count_array to store count of each individual input value
    for (i = 0; ++count_compare && i < k; i++)
        count_array[i] = 0;

    for (i = 0; ++count_compare && i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for (i = 1; ++count_compare && i < k; i++)
        count_array[i] += count_array[i - 1];

    // Populate output array using count_array and input array
    for (i = 0; ++count_compare && i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

    for (i = 0; ++count_compare && i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

    return count_compare;
}

double countingSort_time(int input[], int n)
{
    time_t start, end;
    start = time(NULL);
    countingSort(input, n);
    end = time(NULL);

    double runtime = difftime(end, start);

    return runtime;
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