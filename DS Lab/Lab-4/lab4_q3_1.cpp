#include <iostream>
using namespace std;

// Returns the second largest distinct element, or INT_MIN if it doesn't exist
int findSecondLargest(int *arr, int n) {
    if (n < 2) return -1; // Not enough elements

    int first = arr[0];
    int second = -1; // Sentinel flag (or track via boolean flag)
    bool foundSecond = false;

    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
            foundSecond = true;
        } else if (arr[i] < first) {
            if (!foundSecond || arr[i] > second) {
                second = arr[i];
                foundSecond = true;
            }
        }
    }

    return foundSecond ? second : -1;
}

int main() {
    int n;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findSecondLargest(arr, n);

    if (result != -1)
        cout << "Second largest distinct element = " << result << endl;
    else
        cout << "No second largest distinct element found" << endl;

    return 0;
}