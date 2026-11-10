class Solution {
  public:
    void printList(Node* head) {
        // code here
        Node* temp;
        temp = head;
        while (temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
