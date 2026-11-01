#include <iostream>  ////DONEDDD
using namespace std;

/*
void indexes(int *arr, int n, int p)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i]==p)
            cout << i << " ";
    }
}*/

int occurrences(int *arr, int n, int p)
{
    int count = 0;
    for (int i=0; i<n; i++)
        if (arr[i]==p)
            count++;
    return count;
}

int main()
{
    int n, p;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter element to find: ";
    cin >> p;
    cout << "no. of times " << p << " occurs: " << occurrences(arr, n, p) << endl;
    cout << endl;
    return 0;
}