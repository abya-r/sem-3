#include <cstdlib>  //////

int* rdm(int n)
{
    int *arr = new int[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = rand()%100;
    }
    return arr;
}
