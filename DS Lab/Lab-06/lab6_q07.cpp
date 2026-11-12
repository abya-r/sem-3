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

    New_Node->INFO = info;
    New_Node->NEXT = NULL;

    if (START == NULL)
        START = New_Node;
    else
    {
        Node *Temp = START;
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

// Iterative. Returns position (1-based) or -1 if not found
// Time: O(n), Auxiliary space: O(1)
int Position_Iterative(Node *START, int X)
{
    Node *Temp = START;
    int pos = 1;

    while (Temp != NULL)
    {
        if (Temp->INFO == X)
            return pos;
        Temp = Temp->NEXT;
        pos++;
    }
    return -1;
}

// Recursive. Call with pos = 1. Returns position or -1 if not found
// Time: O(n), Auxiliary space: O(n) for the recursion stack
int Position_Recursive(Node *Temp, int X, int pos=1)
{
    if (Temp == NULL)
        return -1;
    if (Temp->INFO == X)
        return pos;
    return Position_Recursive(Temp->NEXT, X, pos + 1);
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

    int X, pos;

    cout << "\nLinked List: ";
    Traverse_List(START);

    cout << "\n\nEnter element to search: ";
    cin >> X;

    pos = Position_Iterative(START, X);
    if (pos != -1)
        cout << "Iterative: " << X << " present at position " << pos << "\n";
    else
        cout << "Iterative: " << X << " not found in the list\n";

    pos = Position_Recursive(START, X);
    if (pos != -1)
        cout << "Recursive: " << X << " present at position " << pos << "\n";
    else
        cout << "Recursive: " << X << " not found in the list\n";

    return 0;
}