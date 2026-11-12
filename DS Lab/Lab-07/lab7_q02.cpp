class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        Node *temp = head;
        head = head->next;
        temp = NULL;
    }
};
