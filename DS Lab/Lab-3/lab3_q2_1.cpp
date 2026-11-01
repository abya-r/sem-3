#include <iostream>   ////DONEDDD
using namespace std;

int even_elements(int* arr, int n)
{
    int even=0;
    for (int i=0; i<n; i++)
    {
        if (arr[i]%2==0)
            even++;
    }
    return even;
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
