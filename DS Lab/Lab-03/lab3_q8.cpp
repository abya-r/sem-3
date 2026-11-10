#include <iostream>  //
using namespace std;

void lowerTriangle(int** arr, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int N;
    cout << "enter N: ";
    cin >> N;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }
    cout << "enter elements: ";
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cin >> arr[i][j];
    }
    lowerTriangle(arr, N);
    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}