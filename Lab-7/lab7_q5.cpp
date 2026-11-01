class Solution {
  public:
    Node* insertNodeAtPos(Node* head, int pos, int x) {
        // code here
        Node *NewNode = new Node(x);
        Node *temp = head;
        for (int i=1; i<pos; i++)
            temp = temp->next;
        if (pos==0)
        {
            while (temp->next!=head)
                temp = temp->next;
            NewNode->next = head;
            head = NewNode;
            temp->next = NewNode;
            return head;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
        return head;
    }
};