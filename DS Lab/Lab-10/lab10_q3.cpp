#include <iostream>
using namespace std;

#define SIZE 5

struct queue
{
    int array[SIZE];
    int front, rear;
};

void createQueue(struct queue *CQ)
{
    CQ->front = -1;
    CQ->rear = -1;
}

bool isEmpty(struct queue *CQ)
{
    return (CQ->front == -1);
}

bool isFull(struct queue *CQ)
{
    return ((CQ->rear + 1) % SIZE == CQ->front);
}

void enCqueue(struct queue *CQ, int Item)
{
    if (CQ->front == -1 && CQ->rear == -1)
    {
        CQ->front = CQ->rear = 0;
        CQ->array[CQ->rear] = Item;
        cout << "Enqueued successfully." << endl;
    }
    else if (isFull(CQ))
    {
        cout << "Queue Overflow: Circular Queue is full!" << endl;
    }
    else
    {
        CQ->rear = (CQ->rear + 1) % SIZE;
        CQ->array[CQ->rear] = Item;
        cout << "Enqueued successfully." << endl;
    }
}

void deCqueue(struct queue *CQ)
{
    if (isEmpty(CQ))
    {
        cout << "Queue Underflow: Circular Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued item: " << CQ->array[CQ->front] << endl;
    if (CQ->front == CQ->rear)
    {
        CQ->front = CQ->rear = -1;
    }
    else
    {
        CQ->front = (CQ->front + 1) % SIZE;
    }
}

void displayFront(struct queue *CQ)
{
    if (isEmpty(CQ)) cout << "Queue is empty!" << endl;
    else cout << "Front element: " << CQ->array[CQ->front] << endl;
}

void displayRear(struct queue *CQ)
{
    if (isEmpty(CQ)) cout << "Queue is empty!" << endl;
    else cout << "Rear element: " << CQ->array[CQ->rear] << endl;
}

void countElements(struct queue *CQ)
{
    if (isEmpty(CQ))
    {
        cout << "Number of elements: 0" << endl;
        return;
    }
    int count;
    if (CQ->rear >= CQ->front)
        count = CQ->rear - CQ->front + 1;
    else
        count = SIZE - CQ->front + CQ->rear + 1;
    cout << "Number of elements: " << count << endl;
}

void displayQueue(struct queue *CQ)
{
    if (isEmpty(CQ))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Circular Queue elements: ";
    int i = CQ->front;
    while (true)
    {
        cout << CQ->array[i] << " ";
        if (i == CQ->rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main()
{
    struct queue CQ;
    createQueue(&CQ);

    int choice, val;
    do
    {
        cout << "\n--- Circular Queue Menu ---\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Display Front\n"
             << "4. Display Rear\n"
             << "5. Count Elements\n"
             << "6. Display Queue\n"
             << "7. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            enCqueue(&CQ, val);
            break;
        case 2:
            deCqueue(&CQ);
            break;
        case 3:
            displayFront(&CQ);
            break;
        case 4:
            displayRear(&CQ);
            break;
        case 5:
            countElements(&CQ);
            break;
        case 6:
            displayQueue(&CQ);
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}