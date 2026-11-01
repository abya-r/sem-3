#include <iostream>   //DONED
#include <string>
using namespace std;

int isPresent(const string& s, const string& w, int i=0, int j=0)
{
    if (w.length()>s.length())
        return 0;
    
    if (j==w.length())
        return 1;

    if (i>(s.length()-w.length()))
        return 0;

    if (s[i+j]==w[j])
        return isPresent(s, w, i, j+1);

    return isPresent(s, w, i+1, 0);
}

int main()
{
    string s, word;
    cout << "enter statement: ";
    getline(cin>>ws, s);
    cout << "enter word to search for: ";
    getline(cin>>ws, word);
    if (isPresent(s, word))
        cout << "the word is present in your statement";
    else
        cout << "the word is not present in your statement";
    return 0;
}