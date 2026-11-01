#include <iostream>  ////
using namespace std;

struct complex {
    int a;
    int b;
};

complex add(complex& c1, complex&c2)
{
    complex res;
    res.a = c1.a + c2.a;
    res.b = c1.b + c2.b;
    return res;
}

void display(complex& c)
{
    cout << c.a << "+i" << c.b << endl;
}

int main()
{
    complex x, y, sum;
    cout << "enter first imaginary number: ";
    cin >> x.a;
    cin.ignore();
    cin.ignore();
    cin >> x.b;
    cout << "enter second imaginary number: ";
    cin >> y.a;
    cin.ignore();
    cin.ignore();
    cin >> y.b;
    sum = add(x, y);
    cout << "sum: ";
    display(sum);
    return 0;
}