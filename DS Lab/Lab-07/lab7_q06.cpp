class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Dummy node to handle cases where the head node itself has duplicates
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* prev = dummy;
        Node* curr = head;

        while (curr != nullptr) {
            // Check if the current node has duplicates
            if (curr->next != nullptr && curr->data == curr->next->data) {
                int dupVal = curr->data;
                // Skip all nodes with this duplicate value
                while (curr != nullptr && curr->data == dupVal) {
                    Node* temp = curr;
                    curr = curr->next;
                    delete temp; // Free memory of removed nodes
                }
                // Link prev to the first non-duplicate node found
                prev->next = curr;
            } else {
                // No duplicates for curr, move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};