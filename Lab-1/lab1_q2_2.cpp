#include <iostream>   ////
using namespace std;

int mult(int x, int y)
{
    if (y==0)
        return 0;
    return x+mult(x, --y);
}

int main()
{
    int x, y;
    cout << "enter two numbers: ";
    cin >> x >> y;
    cout << x << "*" << y << " = " << mult(x, y);
    return 0;
}