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

int main()
{
    int n, target;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter element to find: ";
    cin >> target;
    int pos = linearSearch(arr, n, target);
    if (pos!=-1)
        cout << "position of " << target << ": " << pos << endl;
    else
        cout << "element not found" << endl;
    return 0;
}