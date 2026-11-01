#include <iostream>   //
#include <string>
using namespace std;

int vowels(string s)
{
    int vow = 0;
    int i = 0;
    while (i<s.length())
    {
        char ch = s[i];
        if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            vow++;
        i++;

    }
    return vow;
}

int main()
{
    string s;
    cout << "enter string: ";
    getline(cin>>ws, s);
    cout << "no. of vowels = " << vowels(s) << endl;
    return 0;
}
