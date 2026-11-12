class Solution {
  public:
    void deleteNode(Node* x) {
        if (x == nullptr || x->next == nullptr) {
            return; // Can't delete if null or last node
        }

        Node* temp = x->next;
        x->data = temp->data;
        x->next = temp->next;

        delete temp;
    }
};