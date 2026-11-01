#include <iostream>
using namespace std;

void trav(int *arr, int n, int target)
{
    int found = 0, first = -1, last = -1;

    for (int i = 0; i < n; i++)
    {
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
    }

    if (found == 0)
    {
        cout << "element not found\n";
        return;
    }

    cout << "\na. number of occurrences = " << found << endl
         << "b. First occurrence = index " << first << endl
         << "c. last occurrence = index " << last << endl;
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

    trav(arr, n, target);
    return 0;
}