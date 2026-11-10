#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueueUsingStack(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    int n, val;
    cout << "Enter number of elements to insert in queue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.push(val);
    }

    reverseQueueUsingStack(q);

    cout << "Reversed Queue (front to rear): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}