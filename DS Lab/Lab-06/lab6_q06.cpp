class Solution {
  public:
    // Iterative. Time: O(n), Auxiliary space: O(1)
    bool searchKey(Node* head, int key) {
        // Code here
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Recursive. Time: O(n), Auxiliary space: O(n) for the recursion stack
    bool searchKeyRec(Node* head, int key) {
        if (head == NULL)
            return false;
        if (head->data == key)
            return true;
        return searchKeyRec(head->next, key);
    }
};
