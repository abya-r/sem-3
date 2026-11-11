class Solution {   ///DONED
  public:
    void reverseStack(stack<int> &st) {
        // code here
        stack<int> aux;

        // move all elements to auxiliary stack
        while (!st.empty()) {
            aux.push(st.top());
            st.pop();
        }

        // swapping aux stack with st
        swap(st, aux);
    }
};