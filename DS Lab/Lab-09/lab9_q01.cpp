#include <iostream>
using namespace std;

#define SIZE 10

struct stack
{
    int array[SIZE];
    int TOP;
};

void Init_Stack(struct stack *STK)
{
    STK->TOP = -1; // -1 means stack is empty
}

bool IsEmpty(struct stack *STK)
{
    return (STK->TOP == -1);
}

bool IsFull(struct stack *STK)
{
    return (STK->TOP == SIZE - 1);
}

// Time: O(1), Auxiliary space: O(1)
void Push(struct stack *STK, int Item)
{
    if (IsFull(STK)) // overflow
    {
        cout << "Stack is full" << endl;
        return;
    }
    STK->TOP = STK->TOP + 1;
    STK->array[STK->TOP] = Item;
}

// Time: O(1), Auxiliary space: O(1)
int Pop(struct stack *STK)
{
    if (IsEmpty(STK)) // underflow
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int Item = STK->array[STK->TOP];
    STK->TOP = STK->TOP - 1;
    return Item;
}

// Time: O(1), Auxiliary space: O(1)
int Peek(struct stack *STK)
{
    if (IsEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return STK->array[STK->TOP];
}

// Time: O(1), Auxiliary space: O(1)
int Count(struct stack *STK)
{
    return STK->TOP + 1;
}

// Time: O(n), Auxiliary space: O(1)
void Print(struct stack *STK) // top to bottom
{
    if (IsEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = STK->TOP; i >= 0; i = i - 1)
        cout << STK->array[i] << " ";
    cout << endl;
}

int main()
{
    struct stack s;
    struct stack *STK = &s;
    Init_Stack(STK);

    char choice;
    do
    {
        cout << endl
             << "Menu:" << endl
             << "a. Push an element onto the stack" << endl
             << "b. Pop an element from the stack" << endl
             << "c. Display the top element" << endl
             << "d. Count the number of elements" << endl
             << "e. Check whether the stack is empty" << endl
             << "f. Check whether the stack is full" << endl
             << "g. Display the stack" << endl
             << "x. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
        {
            int item;
            cout << "Enter number to push: ";
            cin >> item;
            Push(STK, item);
            break;
        }
        case 'b':
            if (IsEmpty(STK))
                cout << "Stack is empty" << endl;
            else
                cout << "Popped item: " << Pop(STK) << endl;
            break;
        case 'c':
            if (IsEmpty(STK))
                cout << "Stack is empty" << endl;
            else
                cout << "Top element: " << Peek(STK) << endl;
            break;
        case 'd':
            cout << "Element count: " << Count(STK) << endl;
            break;
        case 'e':
            if (IsEmpty(STK))
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;
        case 'f':
            if (IsFull(STK))
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
            break;
        case 'g':
            Print(STK);
            break;
        case 'x':
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 'x');

    return 0;
}