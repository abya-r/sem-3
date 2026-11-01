#include <iostream>  //
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

struct Node* Insert_Beginning(struct Node *START, int value)
{
    Node *NewNode = new Node;

    NewNode->INFO = value;
    NewNode->NEXT = START;

    START = NewNode;

    return START;
}

int noOfNodes (Node* START)
{
    Node* temp;
    temp = START;
    int nodes = 0;
    while (temp->NEXT!=NULL)
    {
        nodes++;
        temp = temp -> NEXT;
    }
    return nodes;
}

int main()
{
    Node* START = NULL;
    int val;

    cout << "enter values: (-1 to stop)\n";

    while (val!=-1)
    {
        cin >> val;
        START = Insert_Beginning(START, val);
    }

    cout << "\nno. of nodes = " << noOfNodes(START);

    return 0;
}
