#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool areParenthesesBalanced(string expr)
{
    stack<char> s;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.empty()) return false;

        char x;
        switch (expr[i])
        {
        case ')':
            x = s.top(); s.pop();
            if (x == '{' || x == '[') return false;
            break;
        case '}':
            x = s.top(); s.pop();
            if (x == '(' || x == '[') return false;
            break;
        case ']':
            x = s.top(); s.pop();
            if (x == '(' || x == '{') return false;
            break;
        }
    }
    return s.empty();
}

int main()
{
    string expr;
    cout << "Enter expression with parentheses: ";
    cin >> expr;

    if (areParenthesesBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}