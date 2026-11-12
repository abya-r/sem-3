// sir's method

class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        Node *t1 = head1, *t2 = head2;
        int l1 = 0, l2 = 0;
        while (t1 != nullptr)
        {
            l1++;
            t1 = t1->next;
        }
        while (t2 != nullptr)
        {
            l2++;
            t2 = t2->next;
        }
        int diff = l1 - l2;
        if (diff < 0)
        {
            diff = -diff;
        }
        t1 = head1;
        t2 = head2;
        if (l1 > l2)
        {
            int i = 1;
            while (i <= diff)
            {
                t1 = t1->next;
                i++;
            }
        }
        else
        {
            int i = 1;
            while (i <= diff)
            {
                t2 = t2->next;
                i++;
            }
        }
        bool isIntersection = false;
        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1 == t2)
            {
                isIntersection = true;
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
};

// method - II

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // code here
        Node *t1 = head1, *t2 = head2;
        while (t1!=t2)
        {
            (t1 == NULL) ? t1 = head2 : t1 = t1->next;
            (t2 == NULL) ? t2 = head1 : t2 = t2->next;
        }
        return t1;
    }
};