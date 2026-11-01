#include <iostream>  ////DONEDDD
using namespace std;

int even_elements(int* arr, int n)
{
    if (n==0)
        return 0;
    int even = (arr[n-1]%2==0) ? 1 : 0;
    return even + even_elements(arr, n-1);
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "no. of even elements = " << even_elements(arr, n) << endl;
    return 0;
}