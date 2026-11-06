#include <iostream>
using namespace std;

#define SIZE 10

struct stack
{
    int array[SIZE];
    int TOP;
} STK;

void init_stack(stack *STK)
{
    STK->TOP = -1;
}
void push(stack *STK, int item);
void pop(stack *STK);
int peek(stack *STK);
int elementCount(stack *STK);
bool isEmpty(stack *STK);
bool isFull(stack *STK);
void print(stack *STK);

int main()
{
    init_stack(&STK);

    int num;
    cout << "enter elements for stack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        push(&STK, num);
    }

    cout << "original stack: ";
    print(&STK);

    cout << endl
         << "Menu:" << endl
         << "a. Push element onto stack" << endl
         << "b. Pop element from stack" << endl
         << "c. Display top element" << endl
         << "d. Count no. of elements in stack" << endl
         << "e. Check whether stack is empty" << endl
         << "f. Check whether stack is full" << endl;
    char choice;
    cout << "enter choice: ";
    cin >> choice;

    switch (choice)
    {

    case 'a':
        int a;
        cout << "enter number to push: ";
        cin >> a;
        push(&STK, a);
        cout << "new stack: ";
        print(&STK);
        break;

    case 'b':
        pop(&STK);
        cout << "new stack: ";
        print(&STK);
        break;

    case 'c':
        cout << peek(&STK);
        break;

    case 'd':
        cout << elementCount(&STK);
        break;

    case 'e':
        if (isEmpty(&STK))
            cout << "stack is empty" << endl;
        else
            cout << "stack is not empty" << endl;
        break;

    case 'f':
        if (isFull(&STK))
            cout << "stack is full" << endl;
        else
            cout << "stack is not full" << endl;
        break;

    default:
        cout << "invalid choice.";
    }

    return 0;
}

void push(stack *STK, int item)
{
    if (isFull(STK))
    {
        cout << "stack is full";
        return;
    }
    STK->TOP = STK->TOP + 1;
    STK->array[STK->TOP] = item;
}

void pop(stack *STK)
{
    if (isEmpty(STK))
    {
        cout << "stack is empty";
        return;
    }
    int item = STK->array[STK->TOP];
    STK->TOP = STK->TOP - 1;
    cout << "popped item: " << item << endl;
}

int peek(stack *STK)
{
    return STK->array[STK->TOP];
}

int elementCount(stack *STK)
{
    return STK->TOP + 1;
}

bool isEmpty(stack *STK)
{
    if (STK->TOP == -1)
        return true;
    else
        return false;
}

bool isFull(stack *STK)
{
    if (STK->TOP == SIZE - 1)
        return true;
    else
        return false;
}

void print(stack *STK)
{
    if (STK->TOP == -1)
    {
        cout << "stack is empty";
        return;
    }
    for (int i = STK->TOP; i >= 0; i--)
        cout << STK->array[i] << " ";
}