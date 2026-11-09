#include <iostream>  /////
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

// Time: O(Loc) -> best O(1) (Loc = 1), worst O(n) (end of list). Auxiliary space: O(1)
Node* InsertAt_Given_Loc(Node *START, int info, int Loc)
{
    Node *Temp = START;
    Node *New_Node;

    if (Loc < 1)
    {
        cout << "invalid location !\n";
        return START;
    }

    New_Node = new Node;
    New_Node->INFO = info;

    if (Loc == 1)
    {
        New_Node->NEXT = START;
        START = New_Node;
        return START;
    }

    for (int i = 1; i < Loc - 1 && Temp != NULL; i++)
        Temp = Temp->NEXT;

    if (Temp == NULL)
    {
        cout << "Loc is greater than number of nodes + 1\n";
        delete New_Node;
        return START;
    }

    New_Node->NEXT = Temp->NEXT;
    Temp->NEXT = New_Node;
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

    int Loc;

    cout << "\nList before insertion: ";
    Traverse_List(START);

    cout << "\n\nEnter value and position to insert: ";
    cin >> value >> Loc;

    START = InsertAt_Given_Loc(START, value, Loc);

    cout << "List after insertion: ";
    Traverse_List(START);

    return 0;
}