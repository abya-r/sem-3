// Lab 10 - Q2: Queue using array WITH shifting during enqueue
//
// Time complexity : create O(1), isEmpty O(1), isFull O(1),
//                   enqueue: best O(1), worst O(n) (when elements are shifted),
//                   dequeue O(1), front/rear O(1), count O(1), display O(n)
// Auxiliary space : O(1) for every operation (shifting is done in place)

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
    return (Q->front == -1 || Q->rear == -1);
}

bool isFull(struct queue *Q)
{
    return (Q->rear == SIZE - 1 && Q->front == 0);
}

void enqueue(struct queue *Q, int Item)
{
    if (isEmpty(Q))
    {
        Q->front = Q->rear = 0;
    }
    else
    {
        if (isFull(Q))
        {
            cout << "Queue Overflow: Queue is full!" << endl;
            return;
        }
        if (Q->rear == SIZE - 1) // free space exists before front: shift
        {
            int k, i;
            for (k = Q->front, i = 0; k <= Q->rear; k++, i++)
                Q->array[i] = Q->array[k];
            Q->rear = i - 1;
            Q->front = 0;
            cout << "(Elements shifted towards the beginning)" << endl;
        }
        Q->rear = Q->rear + 1;
    }
    Q->array[Q->rear] = Item;
    cout << "Enqueued successfully." << endl;
}

void dequeue(struct queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue Underflow: Queue is empty!" << endl;
        return;
    }
    int Item = Q->array[Q->front];
    if (Q->rear == Q->front) // only one element
        Q->front = Q->rear = -1;
    else
        Q->front = Q->front + 1;
    cout << "Dequeued item: " << Item << endl;
}

void displayFront(struct queue *Q)
{
    if (isEmpty(Q))
        cout << "Queue is empty!" << endl;
    else
        cout << "Front element: " << Q->array[Q->front] << endl;
}

void displayRear(struct queue *Q)
{
    if (isEmpty(Q))
        cout << "Queue is empty!" << endl;
    else
        cout << "Rear element: " << Q->array[Q->rear] << endl;
}

void countElements(struct queue *Q)
{
    if (isEmpty(Q))
        cout << "Number of elements: 0" << endl;
    else
        cout << "Number of elements: " << (Q->rear - Q->front + 1) << endl;
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
        cout << Q->array[i] << " ";
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
            displayQueue(&Q); // show updated queue
            break;
        case 2:
            dequeue(&Q);
            displayQueue(&Q); // show updated queue
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