#include <iostream>   //DONEDDD..
using namespace std;

// Returns index of first occurrence or -1
int findFirst(int *arr, int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            res = mid;
            high = mid - 1; // Keep searching left
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

// Returns index of last occurrence or -1
int findLast(int *arr, int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            res = mid;
            low = mid + 1; // Keep searching right
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

void binarySearchAnalysis(int *arr, int n, int target) {
    int first = findFirst(arr, n, target);
    
    if (first == -1) {
        cout << "Element not found\n";
        return;
    }

    int last = findLast(arr, n, target);
    int count = last - first + 1;

    cout << "a. Number of occurrences = " << count << endl;
    cout << "b. First occurrence = index " << first << endl;
    cout << "c. Last occurrence = index " << last << endl;
    cout << "d. Indices at which " << target << " occurs: ";
    for (int i = first; i <= last; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, target;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target element: ";
    cin >> target;

    binarySearchAnalysis(arr, n, target);
    return 0;
}