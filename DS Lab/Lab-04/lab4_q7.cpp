class Solution {
  private:
    int findFirst(int arr[], int n, int target) {
        int low = 0, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1; // Keep searching in the left half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(int arr[], int n, int target) {
        int low = 0, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1; // Keep searching in the right half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

  public:
    int countFreq(int arr[], int n, int target) {
        int first = findFirst(arr, n, target);
        if (first == -1) return 0; // Element not present
        
        int last = findLast(arr, n, target);
        return last - first + 1;
    }
};