#include <iostream>  //
using namespace std;

int decToBinary(int n)
{
    if (n==0)
        return 0;
    return (n%2) + 10*decToBinary(n/2);
}

int main()
{
    int n;
    cout << "enter decimal number: ";
    cin >> n;
    cout << "binary equivalent = " << decToBinary(n);
    return 0;
}
