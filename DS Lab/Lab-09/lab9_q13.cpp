#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

void findMinDifference(int index, const vector<int> &stones, int currentSum, int totalSum, int &minDiff)
{
    if (index == stones.size())
    {
        int diff = abs(currentSum - (totalSum - currentSum));
        minDiff = min(minDiff, diff);
        return;
    }

    findMinDifference(index + 1, stones, currentSum + stones[index], totalSum, minDiff);
    findMinDifference(index + 1, stones, currentSum, totalSum, minDiff);
}

int main()
{
    int n;
    cout << "Enter number of stones: ";
    cin >> n;
    vector<int> stones(n);
    int totalSum = 0;
    cout << "Enter weights of stones: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
        totalSum += stones[i];
    }

    int minDiff = INT32_MAX;
    findMinDifference(0, stones, 0, totalSum, minDiff);

    cout << "Minimum possible difference between stone piles: " << minDiff << endl;
    return 0;
}