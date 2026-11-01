#include <iostream>  //////
#include <ctime>
#include "rdm.h"
using namespace std;

void insertionSort(int* arr, int n);
void swap(int* a, int* b);
void printArr(int* arr, int n);

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);
    insertionSort(arr, n);
    delete [] arr;
    return 0;
}

void insertionSort(int* arr, int n)
{
    cout << "original array: ";
    printArr(arr, n);
    for (int i=1; i<n; i++)
    {
        cout << "iteration " << i << ":\t";
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j -= 1;
        }

        arr[j+1] = key;
        printArr(arr, n);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int* arr, int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
