#include <iostream>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

// Time: O(1), Auxiliary space: O(1)
struct Node* Insert_Beginning(struct Node *START, int value)
{
    Node *NewNode = new struct Node;

    NewNode->INFO = value;
    NewNode->NEXT = START;

    START = NewNode;

    return START;
}

// Time: O(n), Auxiliary space: O(1)
void Traverse_List(struct Node *START)
{
    struct Node *Temp = START;

    while (Temp != NULL)
    {
        cout << Temp->INFO << "  ";
        Temp = Temp->NEXT;
    }
    cout << "NULL";
}

// Creating the list: N calls of Insert_Beginning -> Time O(N), Auxiliary space O(1)
// (list is built in reverse order of the input)
int main()
{
    Node *START = NULL;
    int N, i, value;

    cout << "Enter number of nodes: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Invalid number of nodes\n";
        return 0;
    }

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