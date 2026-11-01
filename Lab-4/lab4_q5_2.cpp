#include <iostream>  //////
using namespace std;

// Recursive frequency counter replacing inner/outer loops
void highest_freq_rec(int *arr, int n, int *freq, int i = 0, int j = 0)
{
    if (i == n) return; // Base case

    if (j < n)
    {
        if (arr[j] == arr[i])
            freq[i]++;
        highest_freq_rec(arr, n, freq, i, j + 1);
    }
    else
    {
        highest_freq_rec(arr, n, freq, i + 1, i + 1);
    }
}

void highest_freq(int *arr, int n)
{
    int freq[n] = {0};
    highest_freq_rec(arr, n, freq);

    int maxm = 0, high = arr[0], ind = 0;
    for (int i = 0; i < n; i++)
    {
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