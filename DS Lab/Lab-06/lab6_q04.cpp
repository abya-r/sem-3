class Solution {
  public:
    // Time: O(n), Auxiliary space: O(n) for the recursion stack
    int getCount(Node* head, int nodes=0) {
        // Code here
        if (head == NULL)
            return nodes;
        return getCount(head->next, nodes+1);
    }
};