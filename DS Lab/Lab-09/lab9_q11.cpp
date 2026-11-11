#include <iostream>
using namespace std;

#define SIZE 100

struct stack {
    int array[SIZE];
    int TOP;
};

void Init_Stack(struct stack* STK) {
    STK->TOP = -1;                       // -1 means stack is empty
}

int IsEmpty(struct stack* STK) {
    if (STK->TOP == -1)
        return 1;
    else
        return 0;
}

int IsFull(struct stack* STK) {
    if (STK->TOP == SIZE - 1)
        return 1;
    else
        return 0;
}

void Push(struct stack* STK, int Item) {
    if (STK->TOP == (SIZE - 1)) {        // Check overflow condition
        cout << "Stack is full" << endl;
        return;
    }
    STK->TOP = STK->TOP + 1;
    STK->array[STK->TOP] = Item;
}

int Pop(struct stack* STK) {
    int Item;
    if (STK->TOP == -1) {                // Check underflow condition
        cout << "Stack is empty" << endl;
        return -1;
    }
    Item = STK->array[STK->TOP];
    STK->TOP = STK->TOP - 1;
    return Item;
}

int Peek(struct stack* STK) {
    if (STK->TOP == -1) {                // Check underflow condition
        cout << "Stack is empty" << endl;
        return -1;
    }
    return STK->array[STK->TOP];
}

void Print(struct stack* STK) {          // bottom to top
    if (STK->TOP == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= STK->TOP; i = i + 1)
        cout << STK->array[i] << " ";
    cout << endl;
}

void MonotonicIncreasing(int A[], int n, struct stack* STK) {
    for (int i = 0; i < n; i++) {
        // pop all greater elements to keep the order increasing
        while (!IsEmpty(STK) && Peek(STK) > A[i]) {
            cout << "Pop " << Pop(STK) << endl;
        }
        Push(STK, A[i]);
        cout << "Push " << A[i] << endl;
    }
}

int main() {
    int n, A[SIZE];
    struct stack s;
    struct stack* STK = &s;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    Init_Stack(STK);
    MonotonicIncreasing(A, n, STK);

    cout << "Monotonic increasing stack (bottom to top): ";
    Print(STK);
    return 0;
}