#include <iostream>   ////
using namespace std;

int isPrime(int n)
{
    if (n==0 || n==1)
        return 0;
    static int i=2;
    if (i*i>n)
        return 1;
    if (n%i==0)
        return 0;
    i++;
    isPrime(n);
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    if (isPrime(n))
        cout << "Prime number";
    else
        cout << "Not a prime number";
    return 0;
}