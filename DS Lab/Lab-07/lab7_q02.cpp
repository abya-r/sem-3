class Solution {
  public:
    Node *deleteHead(Node *head) {
        if (head == NULL) return NULL;
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
// Time: O(1), Auxiliary space: O(1)