#include <iostream>  ////DONEDDD
using namespace std;

int product(int* arr, int n)
{
    int prod=1;
    for (int i=0; i<n; i++)
    {
        prod *= arr[i];
    }
    return prod;
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "product of elements = " << product(arr, n) << endl;
    return 0;
}
