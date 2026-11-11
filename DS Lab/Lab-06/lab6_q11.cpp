/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {   ///DONED
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        int zero = 0, one = 0, two = 0;
        while (temp!=NULL)
        {
            switch(temp->data)
            {
                case 0:
                    zero++;
                    break;
                case 1:
                    one++;
                    break;
                case 2:
                    two++;
                    break;
            }
            temp = temp->next;
        }
        temp = head;
        for (int i=0; i<zero; i++)
        {
            temp->data = 0;
            temp = temp->next;
        }
        for (int i=0; i<one; i++)
        {
            temp->data = 1;
            temp = temp->next;
        }
        for (int i=0; i<two; i++)
        {
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }
};