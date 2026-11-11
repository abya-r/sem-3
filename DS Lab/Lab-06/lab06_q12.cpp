/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {   ///DONED
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node *first = head, *second = head;
        for (int i=1; i<=(k-1) && first!=NULL; i++)
        {
            first = first->next;
        }
        if (first==NULL)
            return -1;
        while (first->next!=NULL)
        {
            second = second->next;
            first = first->next;
        }
        return second->data;
    }
};