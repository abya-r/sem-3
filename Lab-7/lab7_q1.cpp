class Solution {
  public:
    Node* insertAtBeginning(Node* tail, int key) {
        // code here
        Node* NewNode = new Node(key);
        if (tail==NULL)
        {
            NewNode->next==NULL;
            tail=NewNode;
            return tail;
        }
        NewNode->next = tail->next;
        tail->next = NewNode;
        return tail;
    }
};