#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rdm.h"

using namespace std;

void printArr(int* arr, int n, const string& msg)
{
    cout << msg;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertOnline(int* arr, int current_size, int val)
{
    int j = current_size - 1;

    // Shift elements larger than val to the right
    while (j >= 0 && arr[j] > val)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = val; // Place new value in correct position
}

int main()
{
    srand(time(0)); // Seed random number generator

    int capacity;
    cout << "enter maximum capacity of array: ";
    cin >> capacity;

    // 1. Get random array using rdm.h header function
    int* randomArr = rdm(capacity);

    // 2. Print original random array
    printArr(randomArr, capacity, "Original Array: ");

    // 3. Process online insertion into target array
    int arr[capacity];
    int size = 0;

    for (int i = 0; i < capacity; i++)
    {
        insertOnline(arr, size, randomArr[i]);
        size++;
        printArr(arr, size, "=>\t");
    }

    // 4. Print final sorted array
    printArr(arr, size, "\nFinal Sorted Array: ");

    delete[] randomArr; // Clean up memory allocated by Rdm()
    return 0;
}