/* Linked List Node Structure
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
} */

class Solution {   ///DONED
  public:
    // Floyd's cycle detection
    // Time: O(n), Auxiliary space: O(1)
    bool detectLoop(Node* head) {
        // code here
        Node *fast = head, *slow = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast==slow)
                return true;
        }
        return false;
    }
};