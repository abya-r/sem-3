#include <iostream>   ////
using namespace std;

int digits(int n)
{
    int d = 0;
    while (n!=0)
    {
        d++;
        n/=10;
    }
    return d;
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << "no. of digits = " << digits(n);
    return 0;
}
