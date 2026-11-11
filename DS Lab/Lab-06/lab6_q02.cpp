class Solution {
  public:
    // Time: O(n), Auxiliary space: O(1)
    void printList(Node* head) {
        // code here
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};