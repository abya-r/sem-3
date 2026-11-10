#include <iostream>  //
using namespace std;

void sumT(int *arr, int n, int T)
{
    int a, b, ai=-1, bi=-1;
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i]+arr[j]==T && arr[i]!=arr[j])
            {
                a = arr[i];
                ai = i;
                b = arr[j];
                bi = j;
            cout << a << "+" << b << " = " << T << endl
                 << "indices: " << ai << ", " << bi << endl;
            }
        }
    }
    if (ai==-1)
        cout << "no such elements exist." << endl;
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
