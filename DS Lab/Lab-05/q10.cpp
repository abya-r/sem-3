class Solution {
  public:
    int minProduct(vector<int> &arr, int k) {
        long long MOD = 1e9 + 7;
        
        // Sort the array to bring the smallest elements to the front
        sort(arr.begin(), arr.end());
        
        long long product = 1;
        
        // Multiply the first k smallest elements
        for (int i = 0; i < k; i++) {
            product = (product * arr[i]) % MOD;
        }
        
        return product;
    }
};