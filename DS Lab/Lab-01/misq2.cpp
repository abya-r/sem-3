#include <iostream>
using namespace std;

int sumOfSquares(int n)
{
    return n*(n+1)*(2*n+1)/6;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << "sum of squares upto " << n << "^2 = " << sumOfSquares(n);
    return 0;
}
