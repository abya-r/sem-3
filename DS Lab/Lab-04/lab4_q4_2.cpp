#include <iostream>  //
using namespace std;

void sumT(int* arr, int n, int T, int i=0, bool found=false)
{
    if (i==n)
    {
        if (found==false)
            cout << "no such elements exist." << endl;
        return;
    }
    for (int j=i+1; j<n; j++)
    {
        if (arr[i]+arr[j]==T && arr[i]!=arr[j])
        {
            found = true;
            cout << arr[i] << "+" << arr[j] << " = " << T << endl
                 << "indices: " << i << ", " << j << endl;
        }
    }
    return sumT(arr, n, T, i+1, found);
}

int main()
{
    int n, T;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter target element: ";
    cin >> T;
    sumT(arr, n, T);
    return 0;
}
