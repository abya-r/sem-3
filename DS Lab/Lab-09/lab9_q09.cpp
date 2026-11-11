class Solution {   ///DONED
  public:
    void deleteMid(stack<int>& s) {
        // code here
        // Start recursion from the top of the stack
        deleteMid_util(s, s.size(), 0);
    }
    
    void deleteMid_util(stack<int> &st, int sizeOfStack, int current)
    {
        // Remove the middle element
        if (current == sizeOfStack / 2)
        {
            st.pop();
            return;
        }

        // Store and remove the top element
        int topElement = st.top();
        st.pop();

        // Recursively reach the middle element
        deleteMid_util(st, sizeOfStack, current + 1);

        // Restore the element after recursion
        st.push(topElement);
    }
};