#include <iostream>
using namespace std;

#define SIZE 5

struct queue
{
    int array[SIZE];
    int front, rear;
};

void createQueue(struct queue *Q)
{
    Q->front = -1;
    Q->rear = -1;
}

bool isEmpty(struct queue *Q)
{
    return (Q->front == -1 || Q->front > Q->rear);
}

bool isFull(struct queue *Q)
{
    return (Q->rear == SIZE - 1);
}

void enqueue(struct queue *Q, int item)
{
    if (isFull(Q))
    {
        cout << "Queue Overflow: Queue is full!" << endl;
        return;
    }
    if (Q->front == -1)
    {
        Q->front = 0;
    }
    Q->rear = Q->rear + 1;
    Q->array[Q->rear] = item;
    cout << "Enqueued successfully." << endl;
}

void dequeue(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue Underflow: Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued item: " << Q->array[Q->front] << endl;
    Q->front = Q->front + 1;
    if (Q->front > Q->rear)
    {
        Q->front = Q->rear = -1; // Reset queue
    }
}

void displayFront(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << Q->array[Q->front] << endl;
}

void displayRear(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Rear element: " << Q->array[Q->rear] << endl;
}

void countElements(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Number of elements: 0" << endl;
        return;
    }
    int count = Q->rear - Q->front + 1;
    cout << "Number of elements: " << count << endl;
}

void displayQueue(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = Q->front; i <= Q->rear; i++)
    {
        cout << Q->array[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct queue Q;
    createQueue(&Q);

    int choice, val;
    do
    {
        cout << "\n--- Linear Queue Menu ---\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Display Front\n"
             << "4. Display Rear\n"
             << "5. Count Elements\n"
             << "6. Check isEmpty\n"
             << "7. Check isFull\n"
             << "8. Display Queue\n"
             << "9. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            enqueue(&Q, val);
            break;
        case 2:
            dequeue(&Q);
            break;
        case 3:
            displayFront(&Q);
            break;
        case 4:
            displayRear(&Q);
            break;
        case 5:
            countElements(&Q);
            break;
        case 6:
            if (isEmpty(&Q)) cout << "Queue is empty." << endl;
            else cout << "Queue is not empty." << endl;
            break;
        case 7:
            if (isFull(&Q)) cout << "Queue is full." << endl;
            else cout << "Queue is not full." << endl;
            break;
        case 8:
            displayQueue(&Q);
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);

    return 0;
}