#include <iostream>  //NOOO
using namespace std;

int fib(int n)
{
    if (n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}

void fibPrint(int n)
{
    if (n<=0)
        return;
    //cout << fib(n-1) << " " << fib(n);  //why not calling recursively??  //understood.
    fibPrint(n-1);
    cout << fib(n) << " ";
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << n << " terms of Fibonacci series: ";
    fibPrint(n);
    return 0;
}
