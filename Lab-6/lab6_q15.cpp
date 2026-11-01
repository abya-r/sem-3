#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int INFO;
    Node *NEXT;
};

bool detectLoop(Node *START)
{
    vector<Node*> visitedNodes;
    
    Node *temp = START;
    while (temp != NULL)
    {
        for (Node* vNode : visitedNodes)
        {
            if (vNode == temp)
            {
                return true;
            }
        }
        visitedNodes.push_back(temp);
        temp = temp->NEXT;
    }
    
    return false;
}