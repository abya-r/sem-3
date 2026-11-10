#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findPreviousSmaller(const vector<int> &arr)
{
    stack<int> st;
    vector<int> pse(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty()) pse[i] = -1;
        else pse[i] = st.top();

        st.push(arr[i]);
    }
    return pse;
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

    vector<int> pse = findPreviousSmaller(arr);
    cout << "Previous Smaller Elements: ";
    for (int x : pse) cout << x << " ";
    cout << endl;
    return 0;
}