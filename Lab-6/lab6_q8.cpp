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

Node* insert_kthLoc (Node* START, int data, int k)
{
    if (k<1)
    {
        cout << "invalid location";
        return START;
    }

    Node* NewNode = new Node;
    NewNode->INFO = data;

    if (k==1)
    {
        NewNode->NEXT = START;
        START = NewNode;
        return START;
    }

    Node* Temp = START;
    for (int i=0; i<k-1 && Temp!=NULL; i++)
        Temp = Temp->NEXT;
    if (Temp==NULL)
    {
        cout << "invalid location: k>n+1";
        return START;
    }
    NewNode->NEXT = Temp->NEXT;
    Temp->NEXT = NewNode;
    return START;
}

void printList(struct Node *START)
{
    struct Node *Temp;

    Temp = START;

    while (Temp != NULL)
    {
        cout << Temp->INFO << "  ";
        Temp = Temp->NEXT;
    }
    cout << "\n";
}

int main()
{
    Node* START = NULL;
    int val, data, k;

    cout << "enter values: (-1 to stop)\n";

    while (val!=-1)
    {
        cin >> val;
        START = insert_End(START, val);
    }

    cout << "list before insertion: ";
    printList(START);

    cout << "enter number and position to insert: ";
    cin >> data >> k;

    insert_kthLoc (START, data, k);

    cout << "list after insertion: ";
    printList(START);

    return 0;
}