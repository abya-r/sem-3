/// DONED

void reverseQueue(queue<int>& q) {
    stack<int> st;
    
    // Transfer all elements from queue to stack
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    
    // Transfer all elements back from stack to queue
    // This reverses the order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}