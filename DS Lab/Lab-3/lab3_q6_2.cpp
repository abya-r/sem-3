#include <iostream>  ////DONEDDD
using namespace std;

int lastIndex(int *arr, int n, int p)
{
    if (n<=0)
        return -1;
    if (arr[n-1]==p)
        return n-1;
    return lastIndex(arr, n-1, p);
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
    cout << "enter target element: ";
    cin >> p;
    int idx = lastIndex(arr, n, p);
    if (idx == -1)
        cout << "element not present in array";
    else
        cout << "last occurrence of " << p << " = index " << idx;
    return 0;
}