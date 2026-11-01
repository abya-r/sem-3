#include <iostream>  //IMPPPPPP
#include <string>
using namespace std;

void fun(string s)
{
    int n = s.length();
    for (int i=0; i<(1<<n); i++)  //(1<<n) = 2^n
    {
        for (int j=0; j<n; j++)
        {
            if (i & (1<<(n-j-1)))
                cout << s[j];
        }
        cout << "\n";
    }
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    fun(s);

    return 0;
}
