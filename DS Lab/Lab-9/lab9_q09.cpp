#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int> &st, int n, int current = 0)
{
    if (st.empty() || current == n) return;

    int x = st.top();
    st.pop();

    deleteMid(st, n, current + 1);

    if (current != n / 2)
    {
        st.push(x);
    }
}

int main()
{
    stack<int> st;
    int num;
    cout << "Enter elements for stack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1) break;
        st.push(num);
    }

    deleteMid(st, st.size());

    cout << "Stack after deleting middle element (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}