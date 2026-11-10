#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

// Time: O(n), Auxiliary space: O(1)
Node* Append_List(Node *START, int info)
{
    Node *New_Node = new Node;
    Node *Temp = START;

    New_Node->INFO = info;
    New_Node->NEXT = NULL;

    if (START == NULL)
        START = New_Node;
    else
    {
        while (Temp->NEXT != NULL)
            Temp = Temp->NEXT;
        Temp->NEXT = New_Node;
    }
    return START;
}

// Links the last node to the node at position pos (testing helper); pos = 0 means no loop
void Create_Loop(Node *START, int pos)
{
    Node *Temp = START;
    Node *loopNode = NULL;
    int count = 1;

    if (pos == 0)
        return;

    while (Temp->NEXT != NULL)
    {
        if (count == pos)
            loopNode = Temp;
        Temp = Temp->NEXT;
        count++;
    }
    if (count == pos)
        loopNode = Temp;

    if (loopNode == NULL)
    {
        cout << "Invalid position, no loop created\n";
        return;
    }
    Temp->NEXT = loopNode;
}

// Visited nodes (addresses) are stored in an array
// Time: O(n^2) (linear scan of the array for every node), Auxiliary space: O(n)
bool Detect_Loop_Array(Node *START)
{
    vector<Node*> visited;
    Node *Temp = START;

    while (Temp != NULL)
    {
        for (int i = 0; i < (int)visited.size(); i++)
            if (visited[i] == Temp)
                return true;

        visited.push_back(Temp);
        Temp = Temp->NEXT;
    }
    return false;
}

int main()
{
    Node *START = NULL;
    int value, pos;

    cout << "enter values: (-1 to stop)\n";
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        START = Append_List(START, value);
    }

    if (START == NULL)
    {
        cout << "List is empty\n";
        return 0;
    }

    cout << "Enter position to which the last node should point (0 for no loop): ";
    cin >> pos;
    Create_Loop(START, pos);

    if (Detect_Loop_Array(START))
        cout << "Loop detected\n";
    else
        cout << "No loop in the linked list\n";

    return 0;
}