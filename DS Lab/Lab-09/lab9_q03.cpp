class SpecialStack {   ///DONED
  public:
    stack<int> st;
    int minEle;

    SpecialStack() {
        // Define Stack
        minEle = -1;
    }

    void push(int x) {
        // Add an element to the top of Stack
        if (st.empty()) {
            minEle = x;
            st.push(x);
        }
        else if (x < minEle) {
            st.push(2*x - minEle);
            minEle = x;
        }
        else {
            st.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if (st.empty()) return;
        int top = st.top();
        st.pop();
        if (top < minEle) {
            minEle = 2*minEle - top;
        }
    }

    int peek() {
        // Returns top element of the Stack
        if (st.empty()) return -1;
        int top = st.top();
        return (minEle > top) ? minEle : top;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMin() {
        // Finds minimum element of Stack
        if (st.empty()) return -1;
        return minEle;
    }
};