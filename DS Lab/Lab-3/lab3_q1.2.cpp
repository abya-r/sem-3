#include <iostream>  ////DONEDDD
#include <algorithm>
using namespace std;

int max_element(int* arr, int n)
{
    if (n==1)
        return arr[0];
    return max(arr[n-1], max_element(arr, n-1));
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    cout << "enter numbers: ";
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "max element = " << max_element(arr, n) << endl;
    return 0;
}