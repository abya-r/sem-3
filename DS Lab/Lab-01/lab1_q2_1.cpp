#include <iostream>   ////
using namespace std;

int mult(int x, int y)
{
    int res = 0;
    while (y!=0)
    {
        res+=x;
        --y;
    }
    return res;
}

int main()
{
    int x, y;
    cout << "enter two numbers: ";
    cin >> x >> y;
    cout << x << "*" << y << " = " << mult(x, y);
    return 0;
}
