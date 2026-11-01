class Solution {
  public:
    int closer(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) return mid;
            if (mid > low && arr[mid - 1] == x) return mid - 1;
            if (mid < high && arr[mid + 1] == x) return mid + 1;

            if (x < arr[mid]) {
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }

        return -1;
    }
};