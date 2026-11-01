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

void Traverse_List(struct Node *START)
{
    struct Node *Temp;

    Temp = START;

    while (Temp != NULL)
    {
        cout << Temp->INFO << "  ";
        Temp = Temp->NEXT;
    }
    cout << "NULL";
}

int main()
{
    struct Node *START = NULL;
    int N, i, value;

    cout << "Enter number of nodes: ";
    cin >> N;

    for (i = 1; i <= N; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> value;

        START = insert_End(START, value);
    }

    cout << "\nLinked List: ";
    Traverse_List(START);

    return 0;
}
