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

// Appends a node at the end in O(1) using END pointer (both START and END may change)
Node* Append_Tail(Node *START, Node **END, int info)
{
    Node *New_Node = new Node;

    New_Node->INFO = info;
    New_Node->NEXT = NULL;

    if (START == NULL)
        START = New_Node;
    else
        (*END)->NEXT = New_Node;

    *END = New_Node;
    return START;
}

// Time: O(n + m), Auxiliary space: O(n + m) for the new nodes
Node* Merge_WithSpace(Node *S1, Node *S2)
{
    Node *START = NULL;
    Node *END = NULL;
    Node *t1 = S1;
    Node *t2 = S2;

    if (S1 == NULL && S2 == NULL)
    {
        cout << "Both lists are empty\n";
        return START;
    }

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->INFO <= t2->INFO)
        {
            START = Append_Tail(START, &END, t1->INFO);
            t1 = t1->NEXT;
        }
        else
        {
            START = Append_Tail(START, &END, t2->INFO);
            t2 = t2->NEXT;
        }
    }

    while (t1 != NULL)
    {
        START = Append_Tail(START, &END, t1->INFO);
        t1 = t1->NEXT;
    }

    while (t2 != NULL)
    {
        START = Append_Tail(START, &END, t2->INFO);
        t2 = t2->NEXT;
    }
    return START;
}

int main()
{
    Node *START1 = NULL;
    Node *START2 = NULL;
    Node *START = NULL;
    int val1 = 0, val2 = 0;

    cout << "enter values for linked list 1 in sorted order: (-1 to stop)\n";
    while (true)
    {
        cin >> val1;
        if (val1 == -1)
            break;
        START1 = Append_List(START1, val1);
    }

    cout << "enter values for linked list 2 in sorted order: (-1 to stop)\n";
    while (true)
    {
        cin >> val2;
        if (val2 == -1)
            break;
        START2 = Append_List(START2, val2);
    }

    cout << "\nList 1: ";
    Traverse_List(START1);
    cout << "\nList 2: ";
    Traverse_List(START2);

    START = Merge_WithSpace(START1, START2);

    cout << "\nMerged list: ";
    Traverse_List(START);

    return 0;
}