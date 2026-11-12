class Solution {
  public:
    vector<Node*> findAnagrams(Node* head, string str) {
        vector<Node*> ans;
        int k = str.length();
        if (head == nullptr || k == 0) return ans;

        vector<int> targetFreq(26, 0);
        for (char c : str) {
            targetFreq[c - 'a']++;
        }

        vector<int> windowFreq(26, 0);
        Node* start = head;
        Node* end = head;
        int count = 0;

        while (end != nullptr) {
            windowFreq[end->data - 'a']++;
            count++;

            if (count == k) {
                if (windowFreq == targetFreq) {
                    ans.push_back(start);
                    Node* nextNode = end->next;
                    end->next = nullptr;
                    
                    start = nextNode;
                    end = nextNode;
                    fill(windowFreq.begin(), windowFreq.end(), 0);
                    count = 0;
                    continue;
                } else {
                    windowFreq[start->data - 'a']--;
                    start = start->next;
                    count--;
                }
            }
            end = end->next;
        }

        return ans;
    }
};