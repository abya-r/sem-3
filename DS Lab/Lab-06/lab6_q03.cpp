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
int Count_Nodes(Node *START)
{
    Node *Temp = START;
    int count = 0;

    if (START == NULL)
    {
        cout << "List is empty\n";
        return 0;
    }

    while (Temp != NULL)
    {
        count++;
        Temp = Temp->NEXT;
    }
    return count;
}

int main()
{
    Node *START = NULL;
    int value;

    cout << "Enter values (-1 to stop):\n";
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;

        START = Insert_Beginning(START, value);
    }

    int count = Count_Nodes(START);

    cout << "\nNumber of nodes = " << count;

    return 0;
}