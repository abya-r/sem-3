// gfg: get kth node from end

class Solution {   ///DONED
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node *first = head, *second = head;
        for (int i=1; i<=(k-1) && first!=NULL; i++)
        {
            first = first->next;
        }
        if (first==NULL)
            return -1;
        while (first->next!=NULL)
        {
            second = second->next;
            first = first->next;
        }
        return second->data;
    }
};

// question statement: delete kth node from end

Node *deletekthNodeFromEnd(Node *head, int k)
{
    if (head == nullptr)
        return head;

    int l = 0;
    Node *curr = head;

    // Find length of list
    while (curr != nullptr)
    {
        curr = curr->next;
        l++;
    }

    // If n is greater than length, do nothing
    if (k > l)
        return head;

    // If head is the nth node from end
    if (l - k == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Reach the node just before target
    curr = head;
    for (int i = 1; i < l - k; i++)
    {
        curr = curr->next;
    }

    // Delete the target node
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
}