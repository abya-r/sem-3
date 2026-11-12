class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* newNode = new Node(x);
        
        if (head == nullptr) {
            return newNode;
        }
        
        if (x <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->data < x) {
            current = current->next;
        }
        
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
        
        return head;
    }
};