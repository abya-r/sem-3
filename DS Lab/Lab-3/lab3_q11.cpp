#include <iostream>  //
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    int pos = -1;
    for (int i=0; i<n; i++)
    {
        if (arr[i]==target)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void Delete (int arr[], int& n, int target)
{
    int k = linearSearch(arr, n, target);
    if (k<0)
    {
        cout << "Error: element not found" << endl;
        return;
    }
    int d = arr[k];
    int i = k;
    while (i<=n-2)
    {
        arr[i] = arr[i+1];
        i++;
    }
    n -= 1;
    cout << "new array after deletion: " << endl;
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, target;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter element to delete: ";
    cin >> target;
    Delete(arr, n, target);
    return 0;
}