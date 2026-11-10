#include <iostream>  //////
#include <ctime>
#include "rdm.h"
using namespace std;

void selectionSort(int* arr, int n);
//void swap(int* a, int* b);
void printArr(int* arr, int n);

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);
    selectionSort(arr, n);
    delete [] arr;
    return 0;
}

void selectionSort(int* arr, int n)
{
    cout << "original array: ";
    printArr(arr, n);
    for (int i=0; i<n-1; i++)
    {
        cout << "iteration " << i << ":\t";
        int minm = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j]<arr[minm])
                minm = j;
        }
        if (minm!=i)
            swap(arr[i], arr[minm]);
        printArr(arr, n);
    }
}

/*
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}*/

void printArr(int* arr, int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
