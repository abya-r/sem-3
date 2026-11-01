#include <iostream>  ///vector
using namespace std;

bool duplicate (int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i]==arr[j])
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    if (duplicate(arr, n))
        cout << "There are duplicate elements." << endl;
    else
        cout << "There are no duplicate elements." << endl;
    return 0;
}