#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> s;
    stack<int> minStack;

public:
    void push(int val)
    {
        s.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if (s.empty()) return;
        if (s.top() == minStack.top())
        {
            minStack.pop();
        }
        s.pop();
    }

    int top()
    {
        if (s.empty()) return -1;
        return s.top();
    }

    int getMin()
    {
        if (minStack.empty()) return -1;
        return minStack.top();
    }
};

int main()
{
    MinStack ms;
    int num;
    cout << "Enter elements for MinStack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1) break;
        ms.push(num);
    }

    cout << "Current Minimum Element: " << ms.getMin() << endl;
    ms.pop();
    cout << "Minimum Element after pop: " << ms.getMin() << endl;
    return 0;
}