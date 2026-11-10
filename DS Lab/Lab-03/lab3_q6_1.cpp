#include <iostream>  ////DONEDDD
using namespace std;

int lastIndex(int *arr, int n, int p)
{
    for (int i=n-1; i>=0; i--)
    {
        if (arr[i]==p)
        {
            return i;
        }
    }
    return -1;
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
    if (lastIndex(arr, n, p)==-1)
        cout << "element not present in array";
    else
        cout << "last occurrence of " << p << " = index " << lastIndex(arr, n, p);
    return 0;
}