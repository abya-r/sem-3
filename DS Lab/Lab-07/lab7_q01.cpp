class Solution {
  public:
    Node* insertAtBeginning(Node* tail, int key) {
        Node* newNode = new Node(key);
        if (tail == NULL) {
            newNode->next = newNode;   // single node points to itself
            return newNode;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        return tail;
    }
};
// Time: O(1), Auxiliary space: O(1)