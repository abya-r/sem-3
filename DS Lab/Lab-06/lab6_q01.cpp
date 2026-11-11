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

// Creates a list of N nodes (list is built in reverse order of the input)
// N calls of Insert_Beginning -> Time: O(N), Auxiliary space: O(1)
Node* Create_List(int N)
{
    Node *START = NULL;
    int value;

    if (N <= 0)
    {
        cout << "Invalid number of nodes\n";
        return START;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> value;

        START = Insert_Beginning(START, value);
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

int main()
{
    Node *START = NULL;
    int N;

    cout << "Enter number of nodes: ";
    cin >> N;

    START = Create_List(N);

    cout << "\nLinked List: ";
    Traverse_List(START);

    return 0;
}