#include <iostream>
using namespace std;

int fact(int n)
{
    int ans=1;
    while (n!=0 && n!=1)
    {
        ans*=n;
        n-=1;
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << n << "! = " << fact(n);
    return 0;
}
