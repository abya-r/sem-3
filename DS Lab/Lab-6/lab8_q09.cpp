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

// Time: O(Loc) -> best O(1) (Loc = 1), worst O(n). Auxiliary space: O(1)
Node* DeleteFromLoc_List(Node *START, int Loc)
{
    Node *Prev = START;
    Node *Temp = START;

    if (START == NULL || Loc <= 0)
    {
        cout << "Empty Linked List or invalid loc\n";
        return START;
    }

    if (Loc == 1)
    {
        START = START->NEXT;
        delete Temp;
        return START;
    }

    for (int i = 1; i <= Loc - 1 && Temp != NULL; i++)
    {
        Prev = Temp;
        Temp = Temp->NEXT;
    }

    if (Temp == NULL)
    {
        cout << "Loc is greater than the total number of nodes\n";
        return START;
    }

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

    int Loc;

    cout << "\nList before deletion: ";
    Traverse_List(START);

    cout << "\n\nEnter position to delete: ";
    cin >> Loc;

    START = DeleteFromLoc_List(START, Loc);

    cout << "List after deletion: ";
    Traverse_List(START);

    return 0;
}