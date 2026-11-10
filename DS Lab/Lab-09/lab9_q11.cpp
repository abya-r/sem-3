#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void buildMonotonicIncreasingStack(const vector<int> &arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
        st.push(arr[i]);
    }

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    cout << "Monotonic Increasing Stack (bottom to top): ";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildMonotonicIncreasingStack(arr);
    return 0;
}