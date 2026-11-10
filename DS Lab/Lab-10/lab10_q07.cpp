#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        q1.pop();
    }

    int top()
    {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    StackUsingQueues st;
    int n, val;
    cout << "Enter number of elements to push onto stack: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }

    cout << "Top element of stack: " << st.top() << endl;
    cout << "Popping top element..." << endl;
    st.pop();
    cout << "New top element: " << st.top() << endl;

    return 0;
}