#include <iostream>
using namespace std;

void trav(int *arr, int n, int target, int i = 0, int found = 0, int first = -1, int last = -1)
{
    if (i == n)
    {
        if (found == 0)
        {
            cout << "element not found";
            return;
        }
        cout << "\na. number of occurrences = " << found << endl
             << "b. First occurrence = index " << first << endl
             << "c. last occurrence = index " << last << endl;
        return;
    }

    if (arr[i] == target)
    {
        if (found == 0)
        {
            cout << "d. indices at which " << target << " occurs: ";
            first = i;
        }
        cout << i << " ";
        last = i;
        found++;
    }

    trav(arr, n, target, i + 1, found, first, last);
}

int main()
{
    int n, target;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "enter target element: ";
    cin >> target;

    // Called with just 3 mandatory arguments!
    trav(arr, n, target);
    return 0;
}