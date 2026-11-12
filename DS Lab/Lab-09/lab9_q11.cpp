#include <iostream>
using namespace std;

#define SIZE 100

struct stack
{
    int array[SIZE];
    int TOP;
};

void Init_Stack(struct stack *STK)
{
    STK->TOP = -1; // -1 means stack is empty
}

int IsEmpty(struct stack *STK)
{
    return (STK->TOP == -1);
}

int IsFull(struct stack *STK)
{
    return (STK->TOP == SIZE - 1);
}

void Push(struct stack *STK, int Item)
{
    if (IsFull(STK)) // overflow
    {
        cout << "Stack is full" << endl;
        return;
    }
    STK->TOP = STK->TOP + 1;
    STK->array[STK->TOP] = Item;
}

int Pop(struct stack *STK)
{
    if (IsEmpty(STK)) // underflow
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int Item = STK->array[STK->TOP];
    STK->TOP = STK->TOP - 1;
    return Item;
}

int Peek(struct stack *STK)
{
    if (IsEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return STK->array[STK->TOP];
}

void Print(struct stack *STK) // bottom to top
{
    if (IsEmpty(STK))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= STK->TOP; i = i + 1)
        cout << STK->array[i] << " ";
    cout << endl;
}

// Time: O(n) (each element is pushed and popped at most once), Auxiliary space: O(n)
// Elements equal to the top are kept (non-decreasing from bottom to top).
// For a strictly increasing stack change '>' to '>=' in the while condition.
void MonotonicIncreasing(int A[], int n, struct stack *STK)
{
    for (int i = 0; i < n; i++)
    {
        // pop all greater elements to keep the order increasing
        while (!IsEmpty(STK) && Peek(STK) > A[i])
            cout << "Pop " << Pop(STK) << endl;
        Push(STK, A[i]);
        cout << "Push " << A[i] << endl;
    }
}

int main()
{
    int n, A[SIZE];
    struct stack s;
    struct stack *STK = &s;

    cout << "Enter number of elements (1 to " << SIZE << "): ";
    cin >> n;
    if (n < 1 || n > SIZE)
    {
        cout << "Invalid number of elements" << endl;
        return 0;
    }
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    Init_Stack(STK);
    MonotonicIncreasing(A, n, STK);

    cout << "Monotonic increasing stack (bottom to top): ";
    Print(STK);
    return 0;
}