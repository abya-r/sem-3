#include <iostream> ////DONEDDD
using namespace std;

bool isFound(int *arr, int n, int p)
{
    if (n<=0)
        return false;
    if (arr[n-1]==p)
        return true;
    return isFound(arr, n-1, p);
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
    if (isFound(arr, n, p))
        cout << "element found!";
    else
        cout << "element not found";
}