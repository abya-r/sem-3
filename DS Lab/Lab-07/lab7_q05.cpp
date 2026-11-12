class Solution {
  public:
    Node* insertNodeAtPos(Node* head, int pos, int x) {
        if (head == NULL) {
            if (pos != 0) {
                cout << "Invalid position" << endl;
                return head;
            }
            Node* newNode = new Node(x);
            newNode->next = newNode;
            return newNode;
        }
        int n = 1;
        Node* temp = head;
        while (temp->next != head) {      // temp ends at the tail
            n++;
            temp = temp->next;
        }
        if (pos < 0 || pos > n) {
            cout << "Invalid position" << endl;
            return head;
        }
        Node* newNode = new Node(x);
        if (pos == 0) {
            newNode->next = head;
            temp->next = newNode;         // temp is the tail
            return newNode;
        }
        temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
};
// Time: O(n), Auxiliary space: O(1)