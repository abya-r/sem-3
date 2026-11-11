/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {   ///DONED
  public:
    Node* reverseList(Node* head) {
        // code here
        if (head==NULL)
            return NULL;
        Node* c = head;
        Node* n = head->next;
        Node* p = NULL;
        c->next = NULL;
        while (n!=NULL)
        {
            p = c;
            c = n;
            n = n->next;
            c->next = p;
        }
        return c;
    }
};