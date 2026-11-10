#include <iostream>
#include <queue>
using namespace std;

void reverseQueueRecursive(queue<int> &q)
{
    if (q.empty())
        return;

    int frontElement = q.front();
    q.pop();

    reverseQueueRecursive(q);

    q.push(frontElement);
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

    reverseQueueRecursive(q);

    cout << "Reversed Queue (front to rear): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}