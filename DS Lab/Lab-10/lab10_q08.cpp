/// DONED

class myQueue {
    stack<int> s1, s2;

  public:
    myQueue() {
        // stacks are empty by default
    }

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        // If both stacks are empty, do nothing
        if (s1.empty() && s2.empty())
            return;

        // Refill s2 only when it is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front() {
        if (s1.empty() && s2.empty())
            return -1;

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }
};