class Solution {
  public:
    Node* deleteAllOccurances(Node* head, int x) {
        while (head != nullptr && head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        if (head == nullptr) {
            return nullptr;
        }
        
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->data == x) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};