#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rdm.h"

using namespace std;

void printArr(int* arr, int n, const string& prefix)
{
    cout << prefix;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

void findMostFrequent(int* arr, int n)
{
    if (n == 0) return;

    // Step 1: Sort the array in O(n log n)
    quickSort(arr, 0, n - 1);

    printArr(arr, n, "Sorted Array: ");

    int max_freq = 1;
    int most_frequent_val = arr[0];
    int current_freq = 1;

    // Step 2: Linear scan to find highest frequency block
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            current_freq++;
        }
        else
        {
            // Strict '>' automatically keeps the SMALLEST element in case of frequency ties
            if (current_freq > max_freq)
            {
                max_freq = current_freq;
                most_frequent_val = arr[i - 1];
            }
            current_freq = 1;
        }
    }

    // Check the last contiguous block
    if (current_freq > max_freq)
    {
        max_freq = current_freq;
        most_frequent_val = arr[n - 1];
    }

    cout << "\nMost frequent element: " << most_frequent_val << endl;
    cout << "Frequency: " << max_freq << endl;
}

int main()
{
    srand(time(0)); // Seed random number generator

    int n;
    cout << "enter no. of elements: ";
    cin >> n;

    // 1. Get random array using Rdm() from rdm.h
    int* arr = rdm(n);

    // 2. Print original array
    printArr(arr, n, "Original Array: ");

    // 3. Find and print most frequent element
    findMostFrequent(arr, n);

    delete[] arr; // Clean up memory allocated by Rdm()
    return 0;
}