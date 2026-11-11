/* Linked List Node Structure
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {   ///DONED
  public:
    int getMiddle(Node* head) {
        // code here
        Node *fast = head, *slow = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
};