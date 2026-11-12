class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
        Node* curr = head;
        while (curr != nullptr) {
            curr->data = getNearestPrime(curr->data);
            curr = curr->next;
        }
        return head;
    }
    int getNearestPrime(int n) {
        for (int d = 0; ; d++) {
            if (n-d >= 2 && isPrime(n-d)) {
                return n-d;
            }
            if (d > 0 && isPrime(n+d)) {
                return n+d;
            }
        }
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
};

/*
wheel factorization:
    every prime number >3 can be written in the form of 6k(+/-)1.
*/