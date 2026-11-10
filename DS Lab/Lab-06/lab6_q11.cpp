class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        int zero=0, one=0, two=0;
        while (temp!=NULL)
        {
            switch (temp->data)
            {
                case 0: zero++; break;
                case 1: one++; break;
                case 2: two++; break;
            }
            temp = temp->next;
        }
        temp = head;
        while (int i=0; i<zero; i++)
        {
            temp->data = 0;
            temp = temp->next;
        }
    }
};