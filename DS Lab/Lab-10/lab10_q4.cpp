#include <iostream>
using namespace std;

struct Node
{
    int INFO;
    struct Node *NEXT;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void createEmptyQueue(struct Queue *Q)
{
    Q->front = Q->rear = NULL;
}

bool isEmpty(struct Queue *Q)
{
    return (Q->front == NULL);
}

void enLqueue(struct Queue *Q, int Item)
{
    struct Node *New_node = new struct Node();
    if (New_node == NULL)
    {
        cout << "Queue Overflow: Out of memory!" << endl;
        return;
    }
    New_node->INFO = Item;
    New_node->NEXT = NULL;

    if (Q->front == NULL || Q->rear == NULL)
    {
        Q->front = Q->rear = New_node;
    }
    else
    {
        (Q->rear)->NEXT = New_node;
        Q->rear = New_node;
    }
    cout << "Enqueued successfully." << endl;
}

void deLqueue(struct Queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue Underflow: Queue is empty!" << endl;
        return;
    }
    struct Node *Temp = Q->front;
    cout << "Dequeued item: " << Temp->INFO << endl;

    if (Q->rear == Q->front)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = (Q->front)->NEXT;
    }
    delete Temp;
}

void displayFront(struct Queue *Q)
{
    if (isEmpty(Q)) cout << "Queue is empty!" << endl;
    else cout << "Front element: " << (Q->front)->INFO << endl;
}

void displayRear(struct Queue *Q)
{
    if (isEmpty(Q)) cout << "Queue is empty!" << endl;
    else cout << "Rear element: " << (Q->rear)->INFO << endl;
}

void countElements(struct Queue *Q)
{
    int count = 0;
    struct Node *Temp = Q->front;
    while (Temp != NULL)
    {
        count++;
        Temp = Temp->NEXT;
    }
    cout << "Number of elements: " << count << endl;
}

void displayQueue(struct Queue *Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Linked Queue elements: ";
    struct Node *Temp = Q->front;
    while (Temp != NULL)
    {
        cout << Temp->INFO << " ";
        Temp = Temp->NEXT;
    }
    cout << endl;
}

int main()
{
    struct Queue Q;
    createEmptyQueue(&Q);

    int choice, val;
    do
    {
        cout << "\n--- Linked Queue Menu ---\n"
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
            enLqueue(&Q, val);
            break;
        case 2:
            deLqueue(&Q);
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