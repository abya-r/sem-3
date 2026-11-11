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


// M-I: WITH AUXILLARY SPACE

class Solution {
  public:
    // Appends (copies of) all 0s, then all 1s, then all 2s into a new list
    // Time: O(n) (3 passes), Auxiliary space: O(n) for the n new nodes
    Node* segregate(Node* head) {
        Node* newHead = NULL;
        Node* tail = NULL;

        for (int val = 0; val <= 2; val++)
        {
            Node* temp = head;
            while (temp != NULL)
            {
                if (temp->data == val)
                {
                    Node* newNode = new Node(val);
                    if (newHead == NULL)
                        newHead = newNode;
                    else
                        tail->next = newNode;
                    tail = newNode;
                }
                temp = temp->next;
            }
        }
        return newHead;
    }
};

// M-II: WITHOUT AUXILLARY SPACE
class Solution {
  public:
    // Time: O(n) (two passes), Auxiliary space: O(1) (3 counters). Links are not changed.
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