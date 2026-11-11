#include <bits/stdc++.h>   ///DONED
using namespace std;

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        deque<long long> dq;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            dq.push_back(x);
        }

        int turn = 1;      // 1 = Aman, 0 = Akshat
        int lastMove = 1;

        while (dq.size() > 1) {
            lastMove = turn;
            int rotations = (turn == 1) ? 1 : 2;

            // Move 1: top goes to bottom
            for (int r = 0; r < rotations; r++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            // Move 2: throw the top away
            dq.pop_front();

            turn = 1 - turn;
        }

        cout << lastMove << " " << dq.front() << "\n";
    }
    return 0;
}