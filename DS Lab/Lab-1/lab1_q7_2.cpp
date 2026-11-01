#include <iostream>   ////
using namespace std;

void factors(int n)
{
    static int i=1;
    if (i>n/2)
        return;
    else if (n%i==0)
        cout << i << " ";
    i++;
    factors (n);
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
