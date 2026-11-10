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
    return (Q->rear == SIZE - 1 && Q->front == 0);
}

void enqueue(struct queue *Q, int Item)
{
    if (Q->front == -1 || Q->rear == -1)
    {
        Q->front = Q->rear = 0;
        Q->array[Q->rear] = Item;
        cout << "Enqueued successfully." << endl;
    }
    else if (Q->rear == SIZE - 1)
    {
        if (Q->front == 0)
        {
            cout << "Queue Overflow: Queue is full!" << endl;
            return;
        }
        // Shift elements to the beginning
        int k, i;
        for (k = Q->front, i = 0; k <= Q->rear; k++, i++)
        {
            Q->array[i] = Q->array[k];
        }
        Q->rear = i - 1;
        Q->front = 0;
        
        Q->rear = Q->rear + 1;
        Q->array[Q->rear] = Item;
        cout << "Enqueued with shifting successfully." << endl;
    }
    else
    {
        Q->rear = Q->rear + 1;
        Q->array[Q->rear] = Item;
        cout << "Enqueued successfully." << endl;
    }
}

void dequeue(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue Underflow: Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued item: " << Q->array[Q->front] << endl;
    if (Q->rear == Q->front)
    {
        Q->front = Q->rear = -1;
    }
    else
    {
        Q->front = Q->front + 1;
    }
}

void displayFront(struct queue *Q)
{
    if (isEmpty(Q)) cout << "Queue is empty!" << endl;
    else cout << "Front element: " << Q->array[Q->front] << endl;
}

void displayRear(struct queue *Q)
{
    if (isEmpty(Q)) cout << "Queue is empty!" << endl;
    else cout << "Rear element: " << Q->array[Q->rear] << endl;
}

void countElements(struct queue *Q)
{
    if (isEmpty(Q)) cout << "Number of elements: 0" << endl;
    else cout << "Number of elements: " << (Q->rear - Q->front + 1) << endl;
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
        cout << "\n--- Queue with Shifting Menu ---\n"
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
            displayQueue(&Q);
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