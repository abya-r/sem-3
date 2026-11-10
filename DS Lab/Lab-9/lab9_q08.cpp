#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &st)
{
    stack<int> temp1, temp2;

    while (!st.empty())
    {
        temp1.push(st.top());
        st.pop();
    }
    while (!temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }
    while (!temp2.empty())
    {
        st.push(temp2.top());
        temp2.pop();
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

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}