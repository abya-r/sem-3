class Solution {   ///DONED
  public:
    int getCount(Node* head, int nodes=0) {
        // Code here
        if (head->next == NULL)
            return nodes+1;
        return getCount(head->next, nodes+1);
    }
};