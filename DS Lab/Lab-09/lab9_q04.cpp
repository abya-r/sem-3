#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string exp;
    cout << "Enter Infix Expression: ";
    cin >> exp;

    cout << "Postfix Expression: " << infixToPostfix(exp) << endl;
    return 0;
}