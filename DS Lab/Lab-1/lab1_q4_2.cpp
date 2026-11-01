#include <iostream>
using namespace std;

int digits(int n)
{
    if (n/10==0)
        return 1;
    return 1+digits(n/10);
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << "no. of digits = " << digits(n);
    return 0;
}
