class Solution {
  public:
    int findSize(Node *head) {
        // Code Here
        Node *temp = head;
        int size = 0;
        while (temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};