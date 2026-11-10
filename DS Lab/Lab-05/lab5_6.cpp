#include <iostream>  //////
#include <ctime>
#include "rdm.h"
using namespace std;

void merge(int arr[], int l, int mid, int h, int n);
void mergeSort(int arr[], int l, int h, int n);
void printArr(int* arr, int n);

int mergePassCount = 0; // Global counter to label merge operations

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);

    cout << "Initial array:\t";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1, n);

    cout << "Sorted array:\t";
    printArr(arr, n);

    delete [] arr;
    return 0;
}

void merge(int arr[], int l, int mid, int h, int n)
{
    int i = l;       // Pointer for left subarray
    int j = mid + 1; // Pointer for right subarray
    int k = 0;       // Index for temp array

    int* C = new int[h - l + 1]; // Temp array sized exactly for the range

    // Merge elements maintaining stability (<= preserves order)
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
            C[k++] = arr[i++];
        else
            C[k++] = arr[j++];
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
        C[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= h)
        C[k++] = arr[j++];

    // Copy merged range back to original array
    for (int x = 0; x < k; x++)
        arr[l + x] = C[x];

    delete[] C;

    // Print progress after this merge operation
    mergePassCount++;
    cout << "Merge " << mergePassCount << " (Subarray [" << l << ".." << h << "]): ";
    printArr(arr, n);
}

void mergeSort(int arr[], int l, int h, int n) {
    if (l < h) {
        int mid = l + (h - l) / 2; // Prevents potential overflow
        
        mergeSort(arr, l, mid, n);      // Sort left half
        mergeSort(arr, mid + 1, h, n);  // Sort right half
        merge(arr, l, mid, h, n);       // Merge sorted halves
    }
}

void printArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}