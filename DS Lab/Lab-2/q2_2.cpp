#include <iostream>   ////
#include <string>
using namespace std;

int isPalindrome(string& s, int index=0)
{
    if (index>=s.length()/2)
        return 1;
    if (s[index] != s[s.length()-1-index])
        return 0;
    return isPalindrome(s, index+1);
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