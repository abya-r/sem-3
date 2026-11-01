class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the bitonic point (maximum element)
            bool leftSmaller = (mid == 0 || arr[mid] > arr[mid - 1]);
            bool rightSmaller = (mid == n - 1 || arr[mid] > arr[mid + 1]);

            if (leftSmaller && rightSmaller) {
                return arr[mid];
            }

            // If mid element is smaller than next element, peak lies on the right
            if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else { // Peak lies on the left
                high = mid - 1;
            }
        }

        return -1;
    }
};