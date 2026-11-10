#include <iostream>   ////
#include <string>
using namespace std;

int isPresent(const string& s, const string& w)
{
    if (w.length()>s.length())
        return 0;
    
    for (int i=0; i<(s.length()-w.length()); i++)
    {
        bool match = true;
        for (int j=0; j<w.length(); j++)
        {
            if (s[i+j]!=w[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return 1;
    }
    return 0;
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