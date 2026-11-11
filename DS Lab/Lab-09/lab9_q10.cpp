class Solution {   ///DONED
  public:
    void sortStack(stack<int> &st) {
        // code here
        stack<int> temp;

        while (!st.empty())
        {
            int x = st.top();
            st.pop();

            // Move smaller elements back to st
            while (!temp.empty() && temp.top() < x)
            {
                st.push(temp.top());
                temp.pop();
            }

            temp.push(x);
        }

        // Move sorted elements back to st
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};