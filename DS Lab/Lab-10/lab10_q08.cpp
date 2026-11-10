#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks
{
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued: " << s1.top() << endl;
        s1.pop();
    }

    int front()
    {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    QueueUsingStacks q;
    int n, val;
    cout << "Enter number of elements to enqueue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Front element of queue: " << q.front() << endl;
    q.dequeue();
    cout << "New front element: " << q.front() << endl;

    return 0;
}