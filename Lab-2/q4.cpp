#include <iostream>   ////
#include <string>
using namespace std;

void concat(char* s1, char* s2)
{
    while(*s1)
        s1++;
    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main()
{
    char s1[50], s2[50];
    cout << "enter first string: ";
    cin.getline(s1, 50);
    cout << "enter second string: ";
    cin.getline(s2, 50);
    concat(s1, s2);
    cout << "concatenated string: " << s1;
    return 0;
}