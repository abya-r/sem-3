class Solution {   ///DONED
  public:
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
