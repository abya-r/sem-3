#include <iostream>   ////
using namespace std;

int power(int x, int y)
{
    int res = 1;
    while(y!=0)
    {
        res*=x;
        --y;
    }
    return res;
}

int main()
{
    int x, y;
    cout << "enter number and power: ";
    cin >> x >> y;
    cout << x << "^" << y << " = " << power(x, y);
    return 0;
}
