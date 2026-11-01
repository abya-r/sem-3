class Solution {
  public:
    void deleteNode(Node* x) {
        // code here
        x->data = x->next->data;
        x->next = x->next->next;
    }
};