#include <iostream>  //
#include "rdm.h"
#include <ctime>
using namespace std;

void bubbleSort(int* arr, int n);
void swap(int* a, int* b);
void printArr(int* arr, int n);

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);
    bubbleSort(arr, n);
    return 0;
}

void bubbleSort(int* arr, int n)
{
    cout << "original array: ";
    printArr(arr, n);
    for (int i=1; i<n; i++)
    {
        cout << "iteration " << i << ":\t";
        for (int j=0; j<n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
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
