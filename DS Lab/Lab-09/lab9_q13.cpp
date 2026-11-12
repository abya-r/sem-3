#include <bits/stdc++.h>
using namespace std;

// Idea: no pile/queue is simulated. Only the INDEX of the surviving stone is tracked.
//
// For a pile [a0, a1, a2, ..., a(m-1)] (a0 on top):
//   Aman   (rotate 1, throw): new pile = [a2, ..., a(m-1), a0]
//   Akshat (rotate 2, throw): new pile = [a3, ..., a(m-1), a0, a1]   (m = 2 gives [a1])
// If the survivor of the smaller pile (size m-1) is at index j, then in the pile of
// size m it was at index:
//   Aman   : j + 2            if j < m-2, else 0
//   Akshat : j + 3            if j < m-3, else j - (m-3)      (m = 2 -> index 1)
//
// Going down from size n to size 1 is a recursion; its calls are kept on an explicit
// stack (sizes only), and the answer is rebuilt while popping them back.
// Turn at pile size m: it is the (n-m)-th turn, Aman if (n-m) is even.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        stack<int> STK;
        for (int m = n; m >= 2; m--)        // "calls": pile sizes n, n-1, ..., 2
            STK.push(m);

        int idx = 0;                        // survivor index in a pile of size 1
        while (!STK.empty())                // "returns": sizes 2, 3, ..., n
        {
            int m = STK.top();
            STK.pop();
            bool aman = ((n - m) % 2 == 0);

            if (aman)
                idx = (idx < m - 2) ? idx + 2 : 0;
            else if (m == 2)
                idx = 1;
            else
                idx = (idx < m - 3) ? idx + 3 : idx - (m - 3);
        }

        // last turn is at pile size 2, i.e. turn number n-2: Aman if n is even
        int lastMove = (n % 2 == 0) ? 1 : 0;
        cout << lastMove << " " << A[idx] << "\n";
    }
    return 0;
}
// Time: O(N) per test case, Auxiliary space: O(N) (stack of pile sizes)