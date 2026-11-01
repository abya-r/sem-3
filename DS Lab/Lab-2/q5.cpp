#include <iostream>   ////
#include <string>
using namespace std;

void prefixes(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        for (int j=0; j<=i; j++)
            cout << s[j];
        cout << "\n";
    }
}

int main()
{
    string s;
    cout << "enter string: ";
    getline(cin>>ws, s);
    prefixes(s);
    return 0;
}