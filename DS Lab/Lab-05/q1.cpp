#include <iostream>  //////
#include "rdm.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin >> n;
    int *arr = rdm(n);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    delete [] arr;
    cout << endl;
    return 0;
}
