#include <iostream>   ////
using namespace std;

void factors(int n)
{
    for (int i=1; i<=n/2; i++)
    {
        if (n%i==0)
            cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << "factors of " << n << ": ";
    factors(n);
    return 0;
}
