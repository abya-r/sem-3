/* Structure of linked list Node
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
class Solution {
  public:
    Node* addOne(Node* head) {
        // code here
        Node *temp = head, *lastNot9 = nullptr;
        while (temp!=nullptr)
        {
            if (temp->data != 9)
            {
                lastNot9 = temp;
            }
            temp = temp->next;
        }
        if (lastNot9==nullptr)
        {
            Node* NewNode = new Node(1);
            NewNode->next = head;
            head = NewNode;
            temp = head->next;
        }
        else
        {
            lastNot9->data += 1;
            temp = lastNot9->next;
        }
        while (temp!=nullptr)
        {
            temp->data = 0;
            temp = temp->next;
        }
        return head;
    }
};