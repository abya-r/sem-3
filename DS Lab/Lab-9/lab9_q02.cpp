#include <iostream>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

void init_lstack(struct Node **TOP)
{
    *TOP = NULL;
}

bool isEmpty(struct Node *TOP)
{
    return (TOP == NULL);
}

void lpush(struct Node **TOP, int item)
{
    struct Node *New_Node = new struct Node();
    if (New_Node == NULL)
    {
        cout << "Stack Overflow: Unable to allocate memory" << endl;
        return;
    }
    New_Node->INFO = item;
    New_Node->NEXT = *TOP;
    *TOP = New_Node;
}

void lpop(struct Node **TOP)
{
    if (isEmpty(*TOP))
    {
        cout << "Stack Underflow: Stack is empty" << endl;
        return;
    }
    struct Node *Temp = *TOP;
    int item = Temp->INFO;
    *TOP = Temp->NEXT;
    delete Temp;
    cout << "Popped item: " << item << endl;
}

int lpeek(struct Node *TOP)
{
    if (isEmpty(TOP))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return TOP->INFO;
}

int elementCount(struct Node *TOP)
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

void print(struct Node *TOP)
{
    if (isEmpty(TOP))
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
    init_lstack(&TOP);

    int num;
    cout << "Enter elements for linked stack: (-1 to stop)" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        lpush(&TOP, num);
    }

    cout << "Original stack: ";
    print(TOP);

    cout << endl
         << "Menu:" << endl
         << "a. Push element" << endl
         << "b. Pop element" << endl
         << "c. Display top element" << endl
         << "d. Count elements" << endl
         << "e. Check empty" << endl;
    char choice;
    cin >> choice;

    switch (choice)
    {
    case 'a':
        int a;
        cout << "Enter number to push: ";
        cin >> a;
        lpush(&TOP, a);
        print(TOP);
        break;
    case 'b':
        lpop(&TOP);
        print(TOP);
        break;
    case 'c':
        cout << "Top element: " << lpeek(TOP) << endl;
        break;
    case 'd':
        cout << "Count: " << elementCount(TOP) << endl;
        break;
    case 'e':
        if (isEmpty(TOP)) cout << "Stack is empty\n";
        else cout << "Stack is not empty\n";
        break;
    default:
        cout << "Invalid choice\n";
    }
    return 0;
}