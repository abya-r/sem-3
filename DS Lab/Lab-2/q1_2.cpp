#include <iostream>  ////
#include <string>
using namespace std;


int isVowel(char ch)
{
    if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return 1;
    return 0;
}

int vowels(string& s, int index=0)
{
    if (index>s.length())
        return 0;
    return isVowel(s[index]) + vowels(s, index+1);
}

int main()
{
    string s;
    cout << "enter string: ";
    getline(cin>>ws, s);
    cout << "no. of vowels = " << vowels(s);
    return 0;
}