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
    cout << "Enter elements for stack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        push(&STK, num);
    }

    cout << "Original stack: ";
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
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 'a':
        int a;
        cout << "Enter number to push: ";
        cin >> a;
        push(&STK, a);
        cout << "New stack: ";
        print(&STK);
        break;
    case 'b':
        pop(&STK);
        cout << "New stack: ";
        print(&STK);
        break;
    case 'c':
        cout << "Top element: " << peek(&STK) << endl;
        break;
    case 'd':
        cout << "Element count: " << elementCount(&STK) << endl;
        break;
    case 'e':
        if (isEmpty(&STK))
            cout << "Stack is empty" << endl;
        else
            cout << "Stack is not empty" << endl;
        break;
    case 'f':
        if (isFull(&STK))
            cout << "Stack is full" << endl;
        else
            cout << "Stack is not full" << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}

void push(stack *STK, int item)
{
    if (isFull(STK))
    {
        cout << "Stack is full" << endl;
        return;
    }
    STK->TOP = STK->TOP + 1;
    STK->array[STK->TOP] = item;
}

void pop(stack *STK)
{
    if (isEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    int item = STK->array[STK->TOP];
    STK->TOP = STK->TOP - 1;
    cout << "Popped item: " << item << endl;
}

int peek(stack *STK)
{
    if (isEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return STK->array[STK->TOP];
}

int elementCount(stack *STK)
{
    return STK->TOP + 1;
}

bool isEmpty(stack *STK)
{
    return (STK->TOP == -1);
}

bool isFull(stack *STK)
{
    return (STK->TOP == SIZE - 1);
}

void print(stack *STK)
{
    if (isEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = STK->TOP; i >= 0; i--)
        cout << STK->array[i] << " ";
    cout << endl;
}