#include <iostream>   ////
using namespace std;

int res = 0;
int reverse(int n)
{
    if (n==0)
        return res;  //wowowoww
    res = res*10 + n%10;
    return reverse(n/10);
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << "reversed no. = " << reverse(n);
    return 0;
}
