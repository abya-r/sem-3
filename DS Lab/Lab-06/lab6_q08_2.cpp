#include <iostream>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

// Time: O(n), Auxiliary space: O(1)
Node* Append_List(Node *START, int info)
{
    Node *New_Node = new Node;
    Node *Temp = START;

    New_Node->INFO = info;
    New_Node->NEXT = NULL;

    if (START == NULL)
        START = New_Node;
    else
    {
        while (Temp->NEXT != NULL)
            Temp = Temp->NEXT;
        Temp->NEXT = New_Node;
    }
    return START;
}

// Time: O(n), Auxiliary space: O(1)
void Traverse_List(struct Node *START)
{
    struct Node *Temp = START;

    if (START == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (Temp != NULL)
    {
        cout << Temp->INFO << "  ";
        Temp = Temp->NEXT;
    }
    cout << "NULL";
}

// Time: O(n), Auxiliary space: O(n) for the recursion stack
void Reverse_Display(Node *Temp)
{
    if (Temp == NULL)
        return;
    Reverse_Display(Temp->NEXT);
    cout << Temp->INFO << "  ";
}

int main()
{
    Node *START = NULL;
    int value;

    cout << "Enter values (-1 to stop):\n";
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;

        START = Append_List(START, value);
    }

    cout << "\nOriginal list: ";
    Traverse_List(START);

    cout << "\nReverse display: ";
    if (START == NULL)
        cout << "List is empty";
    else
        Reverse_Display(START);

    return 0;
}