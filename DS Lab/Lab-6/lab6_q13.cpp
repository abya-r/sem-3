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

Node* Traverse_List (Node *START)
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
    Node* START = NULL;
    int val;
    Node *t1 = S1, *t2 = S2;
    while (t1!=NULL && t2!=NULL)
    {
        if (t1->INFO <= t2->INFO)
        {
            START = insert_End(START, t1->INFO);
            t1 = t1->NEXT;
        }
        else
        {
            START = insert_End(START, t2->INFO);
            t2 = t2->NEXT;
        }
    }
    while (t1!=NULL)
    {
        START = insert_End(START, t1->INFO);
        t1 = t1->NEXT;
    }
    while (t2!=NULL)
    {
        START = insert_End(START, t2->INFO);
        t2 = t2->NEXT;
    }

    Traverse_List (START);
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
        //Traverse_List(START1);
    }

    cout << "enter values for linked list 2: (-1 to stop)\n";
    while (1)
    {
        cin >> val2;
        if (val2==-1)
            break;
        START2 = insert_End(START2, val2);
        //Traverse_List(START2);
    }

    mergeLists(START1, START2);

    return 0;
}
