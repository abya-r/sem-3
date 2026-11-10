#include <iostream>
using namespace std;

void findSecondLargestRecursive(int *arr, int n, int i, int first, int second, bool foundSecond) {
    // Base Case: Traversing finished
    if (i == n) {
        if (foundSecond)
            cout << "Second largest distinct element = " << second << endl;
        else
            cout << "No second largest distinct element found" << endl;
        return;
    }

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

    findSecondLargestRecursive(arr, n, i + 1, first, second, foundSecond);
}

int main() {
    int n;
    cout << "enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n < 2) {
        cout << "No second largest distinct element found" << endl;
    } else {
        findSecondLargestRecursive(arr, n, 1, arr[0], -1, false);
    }

    return 0;
}