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

// Returns the address of the node containing info, otherwise NULL
// Time: O(n), Auxiliary space: O(1)
Node* Search_List(Node *START, int info)
{
    Node *Temp = START;

    while (Temp != NULL)
    {
        if (Temp->INFO == info)
            return Temp;
        Temp = Temp->NEXT;
    }
    return NULL;
}

// First find the node, then delete it (first occurrence of X)
// Time: O(n), Auxiliary space: O(1)
Node* Delete_By_Value(Node *START, int X)
{
    Node *Prev = START;
    Node *Temp = Search_List(START, X);

    if (START == NULL)
    {
        cout << "Empty Linked List\n";
        return START;
    }

    if (Temp == NULL)
    {
        cout << X << " is not present in the list\n";
        return START;
    }

    if (Temp == START)
    {
        START = START->NEXT;
        delete Temp;
        return START;
    }

    while (Prev->NEXT != Temp)
        Prev = Prev->NEXT;

    Prev->NEXT = Temp->NEXT;
    delete Temp;
    return START;
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

    int X;

    cout << "\nList before deletion: ";
    Traverse_List(START);

    cout << "\n\nEnter value to delete: ";
    cin >> X;

    START = Delete_By_Value(START, X);

    cout << "List after deletion: ";
    Traverse_List(START);

    return 0;
}