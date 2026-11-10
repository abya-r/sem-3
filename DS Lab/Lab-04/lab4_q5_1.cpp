#include <iostream>  //////
using namespace std;

void highest_freq(int *arr, int n)
{
    int freq[n] = {0};

    // Count frequency of each element starting from its first occurrence
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] == arr[i])
                freq[i]++;
        }
    }

    int maxm = 0, high = arr[0], ind = 0;
    for (int i = 0; i < n; i++)
    {
        // Strict inequality preserves the element that occurs first in case of tie
        if (freq[i] > maxm)
        {
            maxm = freq[i];
            high = arr[i];
            ind = i;
        }
    }

    cout << "most frequent element: " << high << endl
         << "frequency: " << freq[ind] << endl;
}

int main()
{
    int n;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    highest_freq(arr, n);
    return 0;
}