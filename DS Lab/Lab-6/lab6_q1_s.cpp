#include <iostream>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

struct Node* Insert_Beginning(struct Node *START, int value)
{
    Node *NewNode = new struct Node;

    //NewNode = (struct Node*)malloc(sizeof(struct Node));

    NewNode->INFO = value;
    NewNode->NEXT = START;

    START = NewNode;

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

        START = Insert_Beginning(START, value);
    }

    cout << "\nLinked List: ";
    Traverse_List(START);

    return 0;
}
