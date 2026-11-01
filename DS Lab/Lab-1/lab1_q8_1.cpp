#include <iostream> /////////
using namespace std;

int decToBinary(int n)
{
    int res = 0;
    int place = 1;
    while (n != 0)
    {
        res += (n % 2) * place;
        n /= 2;
        place *= 10;
    }
    return res;
}

int main()
{
    int n;
    cout << "enter decimal number: ";
    cin >> n;
    cout << "binary equivalent = " << decToBinary(n);
    return 0;
}
