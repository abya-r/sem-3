#include <iostream>   //DONEDDD
using namespace std;

// Recursive helper for first occurrence
int findFirstRecursive(int *arr, int low, int high, int target, int res = -1)
{
    if (low > high) return res;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return findFirstRecursive(arr, low, mid - 1, target, mid); // Search left
    } else if (arr[mid] < target) {
        return findFirstRecursive(arr, mid + 1, high, target, res);
    } else {
        return findFirstRecursive(arr, low, mid - 1, target, res);
    }
}

// Recursive helper for last occurrence
int findLastRecursive(int *arr, int low, int high, int target, int res = -1) {
    if (low > high) return res;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return findLastRecursive(arr, mid + 1, high, target, mid); // Search right
    } else if (arr[mid] < target) {
        return findLastRecursive(arr, mid + 1, high, target, res);
    } else {
        return findLastRecursive(arr, low, mid - 1, target, res);
    }
}

void binarySearchAnalysisRecursive(int *arr, int n, int target) {
    int first = findFirstRecursive(arr, 0, n - 1, target);
    
    if (first == -1) {
        cout << "Element not found\n";
        return;
    }

    int last = findLastRecursive(arr, 0, n - 1, target);
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

    binarySearchAnalysisRecursive(arr, n, target);
    return 0;
}
