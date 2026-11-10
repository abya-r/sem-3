#include <iostream>
#include <ctime>
#include "rdm.h"
using namespace std;

void printArr(int* arr, int n);

void stableSelectionSort(int* arr, int n)
{
    cout << "Original array: ";
    printArr(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        cout << "Iteration " << i + 1 << ":\t";
        int minm = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minm])
                minm = j;
        }

        // Instead of swap, shift elements right to preserve relative order of duplicates
        int key = arr[minm];
        while (minm > i)
        {
            arr[minm] = arr[minm - 1];
            minm--;
        }
        arr[i] = key;

        printArr(arr, n);
    }
}

void printArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);

    stableSelectionSort(arr, n);

    delete[] arr;
    return 0;
}