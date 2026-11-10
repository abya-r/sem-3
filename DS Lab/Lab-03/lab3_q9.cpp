#include <iostream>  ///inofeegoo
using namespace std;

void insert(int* arr, int& n, int k, int p)
{
    for (int i=n; i>p; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[p] = k;
    n += 1;
}

int main()
{
    int n, k, p, arr[100];
    cout << "enter no. of elements: ";
    cin >> n;
    cout << "enter elements: ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "enter element to insert and its position: ";
    cin >> k >> p;
    insert(arr, n, k, p);
    cout << "array after insertion: " << endl;
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}