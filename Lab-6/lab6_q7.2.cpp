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

void searchList (Node* temp, int target, int pos=0)
{
    if (temp==NULL)
    {
        cout << target << "not found in linked list" << endl;
        return;
    }
    if (temp->INFO==target)
    {
        cout << target << " present at position " << pos+1 << endl;
        return;
    }
    return searchList (temp->NEXT, target, pos+1);
}

int main()
{
    Node* START = NULL;
    int val, target;

    cout << "enter values: (-1 to stop)\n";

    while (val!=-1)
    {
        cin >> val;
        START = insert_End(START, val);
    }

    cout << "enter target element: ";
    cin >> target;

    searchList(START, target);

    return 0;
}

