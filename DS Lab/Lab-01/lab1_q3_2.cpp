#include <iostream>   ////
using namespace std;

int power(int x, int y)
{
    if (y==0)
        return 1;
    return x*power(x, --y);
}

int main()
{
    int x, y;
    cout << "enter number and power: ";
    cin >> x >> y;
    cout << x << "^" << y << " = " << power(x, y);
    return 0;
}
