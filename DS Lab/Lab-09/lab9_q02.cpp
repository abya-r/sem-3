#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

void Init_LStack(struct Node **TOP)
{
    *TOP = NULL; // NULL means stack is empty
}

bool LIsEmpty(struct Node *TOP)
{
    return (TOP == NULL);
}

// A linked stack is "full" only when no more memory can be allocated
bool LIsFull()
{
    struct Node *Temp = (struct Node *)malloc(sizeof(struct Node));
    if (Temp == NULL)
        return true;
    free(Temp);
    return false;
}

// Time: O(1), Auxiliary space: O(1)
void LPush(struct Node **TOP, int Item)
{
    if (LIsFull()) // overflow
    {
        cout << "Unable to allocate memory" << endl;
        return;
    }
    struct Node *New_Node = (struct Node *)malloc(sizeof(struct Node));
    New_Node->INFO = Item;
    New_Node->NEXT = *TOP;
    *TOP = New_Node;
}

// Time: O(1), Auxiliary space: O(1)
int LPop(struct Node **TOP)
{
    if (LIsEmpty(*TOP)) // underflow
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    struct Node *Temp = *TOP;
    int Item = Temp->INFO;
    *TOP = Temp->NEXT;
    free(Temp);
    return Item;
}

// Time: O(1), Auxiliary space: O(1)
int LPeek(struct Node *TOP)
{
    if (LIsEmpty(TOP))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return TOP->INFO;
}

// Time: O(n), Auxiliary space: O(1)
int LCount(struct Node *TOP)
{
    int count = 0;
    struct Node *Temp = TOP;
    while (Temp != NULL)
    {
        count++;
        Temp = Temp->NEXT;
    }
    return count;
}

// Time: O(n), Auxiliary space: O(1)
void LPrint(struct Node *TOP) // top to bottom
{
    if (LIsEmpty(TOP))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    struct Node *Temp = TOP;
    while (Temp != NULL)
    {
        cout << Temp->INFO << " ";
        Temp = Temp->NEXT;
    }
    cout << endl;
}

int main()
{
    struct Node *TOP;
    Init_LStack(&TOP);

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
            LPush(&TOP, item);
            break;
        }
        case 'b':
            if (LIsEmpty(TOP))
                cout << "Stack is empty" << endl;
            else
                cout << "Popped item: " << LPop(&TOP) << endl;
            break;
        case 'c':
            if (LIsEmpty(TOP))
                cout << "Stack is empty" << endl;
            else
                cout << "Top element: " << LPeek(TOP) << endl;
            break;
        case 'd':
            cout << "Element count: " << LCount(TOP) << endl;
            break;
        case 'e':
            if (LIsEmpty(TOP))
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;
        case 'f':
            if (LIsFull())
                cout << "Stack is full (no memory)" << endl;
            else
                cout << "Stack is not full" << endl;
            break;
        case 'g':
            LPrint(TOP);
            break;
        case 'x':
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 'x');

    while (!LIsEmpty(TOP)) // free remaining nodes
        LPop(&TOP);

    return 0;
}