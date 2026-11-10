#include <iostream>
using namespace std;

void maxOccur(const int* arr, int n)
{
    if (n <= 0)
        return;

    int max_element = arr[0];
    int max_freq = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > max_freq)
        {
            max_freq = count;
            max_element = arr[i];
        }
    }
    cout << "Most frequent element: " << max_element << endl;
    cout << "Frequency: " << max_freq << endl;
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
    maxOccur(arr, n);
    return 0;
}