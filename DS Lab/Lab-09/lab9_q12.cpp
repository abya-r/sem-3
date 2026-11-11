class Solution {   ///DONED
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> result(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            // pop elements from stack until a smaller 
            // element is found or stack becomes empty
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // if stack is not empty, top is nearest smaller
            if (!st.empty()) {
                result[i] = st.top();
            }

            // push current element to stack
            st.push(arr[i]);
        }
        return result;
    }
};