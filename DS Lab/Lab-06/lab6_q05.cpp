class Solution {
  public:
    // Time: O(n), Auxiliary space: O(1) (the returned vector is output space)
    vector<int> printList(Node *head) {
        // code here
        vector<int> res;
        Node* temp = head;
        while (temp != NULL)
        {
            res.push_back(temp->data);
            temp = temp->next;
        }
        return res;
    }
};