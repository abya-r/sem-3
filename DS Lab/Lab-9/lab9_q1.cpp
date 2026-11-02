#include <iostream>
using namespace std;

#define SIZE 10

struct stack {
    int array[SIZE];
    int TOP;
}STK;

int main()
{
    cout << "Menu:" << endl
         << "a. Push element onto stack" << endl
         << "b. Pop element from stack" << endl
         << "c. Display top element" << endl
         << "d. Count no. of elements in stack" << endl
         << "e. Check whether stack is empty" << endl
         << "f. Check whether stack is full" << endl;
    char choice;
    cout << "enter choice: ";
    cin >> choice;

    switch(choice)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    default:
    }
}
