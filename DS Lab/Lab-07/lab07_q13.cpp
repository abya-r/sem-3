class Solution {
  public:
    Node* addPolynomial(Node *head1, Node *head2) {
        Node* dummy = new Node(0, 0);
        Node* tail = dummy;
        
        Node* p1 = head1;
        Node* p2 = head2;
        
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->pow > p2->pow) {
                tail->next = new Node(p1->coeff, p1->pow);
                tail = tail->next;
                p1 = p1->next;
            } else if (p2->pow > p1->pow) {
                tail->next = new Node(p2->coeff, p2->pow);
                tail = tail->next;
                p2 = p2->next;
            } else {
                int sumCoeff = p1->coeff + p2->coeff;
                if (sumCoeff != 0) {
                    tail->next = new Node(sumCoeff, p1->pow);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        while (p1 != nullptr) {
            tail->next = new Node(p1->coeff, p1->pow);
            tail = tail->next;
            p1 = p1->next;
        }
        
        while (p2 != nullptr) {
            tail->next = new Node(p2->coeff, p2->pow);
            tail = tail->next;
            p2 = p2->next;
        }
        
        Node* resultHead = dummy->next;
        delete dummy;
        return resultHead;
    }
};