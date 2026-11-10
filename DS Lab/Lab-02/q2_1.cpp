#include <iostream>  ////
#include <string>
using namespace std;

int isPalindrome(string& s)
{
    for(int i=0; i<s.length()/2; i++)
    {
        if (s[i] != s[s.length()-1-i])
            return 0;

            
    }
    return 1;
}

int main()
{
    string s;
    cout << "enter string: ";
    getline(cin>>ws, s);
    if (isPalindrome(s))
        cout << "palindrome";
    else
        cout << "not a palindrome";
    return 0;
}
