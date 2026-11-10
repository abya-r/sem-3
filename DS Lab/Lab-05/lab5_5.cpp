#include <iostream>  //////
#include <ctime>
#include "rdm.h"
using namespace std;

int partition(int* arr, int low, int high, int n);
void quickSort(int* arr, int low, int high, int n);
void swap(int* a, int* b);
void printArr(int* arr, int n);

int passCount = 0; // Global counter to label partitioning steps

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);

    cout << "Initial array:\t";
    printArr(arr, n);

    quickSort(arr, 0, n - 1, n);

    cout << "Sorted array:\t";
    printArr(arr, n);

    delete [] arr;
    return 0;
}

void quickSort(int* arr, int low, int high, int n)
{
    if (low < high)
    {
        int j = partition(arr, low, high, n);
        
        passCount++;
        cout << "Partition " << passCount << " (Pivot " << arr[j] << " / index " << j << "): ";
        printArr(arr, n);

        quickSort(arr, low, j - 1, n);
        quickSort(arr, j + 1, high, n);
    }
}

int partition(int* arr, int low, int high, int n)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}