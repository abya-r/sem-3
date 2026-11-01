#include <iostream>  ////DONEDDD
using namespace std;

/*void indexes(int *arr, int n, int p, int i=0)
{
    if (i==n)
        return;
    if (arr[i]==p)
        cout << i << " ";
    indexes(arr, n, p, i+1);
}*/

int occurrences(int *arr, int n, int p)
{
    if (n<=0)
        return 0;
    int itsp = (arr[n-1]==p) ? 1 : 0;
    return itsp + occurrences(arr, n-1, p);
}

int main()
{
    int n, p;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter element to find: ";
    cin >> p;
    cout << "no. of times " << p << " occurs: " << occurrences(arr, n, p) << endl;
    cout << endl;
    return 0;
}