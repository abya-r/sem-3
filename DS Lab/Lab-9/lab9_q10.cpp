#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &input)
{
    stack<int> tmpStack;
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    while (!tmpStack.empty())
    {
        input.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main()
{
    stack<int> input;
    int num;
    cout << "Enter elements for stack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1) break;
        input.push(num);
    }

    sortStack(input);

    cout << "Sorted Stack (top to bottom): ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
    return 0;
}