#include <iostream>  ////DONEDDD
using namespace std;

bool isFound(int *arr, int n, int p)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i]==p)
            return true;
    }
    return false;
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
    if (isFound(arr, n, p))
        cout << "element found!";
    else
        cout << "element not found";
}