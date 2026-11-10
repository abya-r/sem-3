#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string prefix = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else
        {
            while (!st.empty() && precedence(c) < precedence(st.top()))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string exp;
    cout << "Enter Infix Expression: ";
    cin >> exp;

    cout << "Prefix Expression: " << infixToPrefix(exp) << endl;
    return 0;
}