class Solution {
  public:
    // Function to search element in the given array
    int search(int arr[], int n, int x) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i; // Target found, return index
            }
        }
        return -1; // Target not present in array
    }
};