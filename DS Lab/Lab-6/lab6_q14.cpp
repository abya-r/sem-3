#include <iostream>  //
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

Node* insert_End(Node* START, int data)
{
    Node* NewNode = new Node;
    Node* Temp;

    NewNode->INFO = data;
    NewNode->NEXT = NULL;

    if (START==NULL)
        START = NewNode;
    else
    {
        Temp = START;
        while (Temp->NEXT != NULL)
            Temp = Temp->NEXT;
        Temp->NEXT = NewNode;
    }
    return START;
}

void Traverse_List (Node *START)
{
    Node *Temp = START;
    while (Temp!=NULL)
    {
        cout << Temp->INFO << " ";
        Temp = Temp->NEXT;
    }
}

void mergeLists (Node *S1, Node *S2)
{
    Node* temp;
    temp->NEXT = NULL;
    Node *tail = temp;

    Node *t1 = S1;
    Node *t2 = S2;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->INFO <= t2->INFO)
        {
            tail->NEXT = t1;
            t1 = t1->NEXT;
        }
        else
        {
            tail->NEXT = t2;
            t2 = t2->NEXT;
        }
        tail = tail->NEXT;
    }

    // Attach whichever list still has nodes left
    if (t1 != NULL)
        tail->NEXT = t1;
    else
        tail->NEXT = t2;

    Traverse_List (temp->NEXT);
}

int main()
{
    Node *START1 = NULL;
    Node *START2 = NULL;
    int val1=0, val2=0;

    cout << "enter values for linked list 1: (-1 to stop)\n";
    while (1)
    {
        cin >> val1;
        if (val1==-1)
            break;
        START1 = insert_End(START1, val1);
    }

    cout << "enter values for linked list 2: (-1 to stop)\n";
    while (1)
    {
        cin >> val2;
        if (val2==-1)
            break;
        START2 = insert_End(START2, val2);
    }

    cout << "merged list: ";
    mergeLists(START1, START2);

    return 0;
}