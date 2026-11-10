#include <iostream>  ////DONEDDD
using namespace std;

int max_element(int* arr, int n)
{
    int max = arr[0];
    for (int i=0; i<n; i++)
    {
        if (*(arr+i)>max)
            max = *(arr+i);
    }
    return max;
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    if (n<=0)
    {
        cout << "invalid array size";
        return 0;
    }
    cout << "enter numbers: ";
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "max element = " << max_element(arr, n);
    return 0;
}
