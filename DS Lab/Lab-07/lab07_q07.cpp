class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
        
        // Case 1: If the linked list is empty
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node* current = head;
        
        // Case 2: Insertion before the head (smallest value or new head)
        if (data <= head->data) {
            // Find the last node (tail)
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            return newNode; // New node becomes the head
        }
        
        // Case 3: Insertion in the middle or at the end
        while (current->next != head && current->next->data < data) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        
        return head;
    }
};