// Lab 10 - Q3: Circular queue using array
//
// Time complexity : every operation O(1) except display O(n)
// Auxiliary space : O(1) for every operation (the queue array itself is O(SIZE))

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
    return (CQ->front == -1 || CQ->rear == -1);
}

bool isFull(struct queue *CQ)
{
    // 1st condition: rear at last cell and front at first cell
    // 2nd condition: rear is just behind front
    return ((CQ->rear == SIZE - 1 && CQ->front == 0) || (CQ->rear == CQ->front - 1));
}

void enCqueue(struct queue *CQ, int Item)
{
    if (isEmpty(CQ))
    {
        CQ->front = CQ->rear = 0;
    }
    else if (isFull(CQ))
    {
        cout << "Queue Overflow: Circular Queue is full!" << endl;
        return;
    }
    else if (CQ->rear == SIZE - 1)
    {
        CQ->rear = 0; // start inserting from the beginning
    }
    else
    {
        CQ->rear = CQ->rear + 1;
    }
    CQ->array[CQ->rear] = Item;
    cout << "Enqueued successfully." << endl;
}

void deCqueue(struct queue *CQ)
{
    if (isEmpty(CQ))
    {
        cout << "Queue Underflow: Circular Queue is empty!" << endl;
        return;
    }
    int Item = CQ->array[CQ->front];
    if (CQ->rear == CQ->front)         // only one element
        CQ->front = CQ->rear = -1;
    else if (CQ->front == SIZE - 1)    // front is at last cell
        CQ->front = 0;
    else
        CQ->front = CQ->front + 1;
    cout << "Dequeued item: " << Item << endl;
}

void displayFront(struct queue *CQ)
{
    if (isEmpty(CQ))
        cout << "Queue is empty!" << endl;
    else
        cout << "Front element: " << CQ->array[CQ->front] << endl;
}

void displayRear(struct queue *CQ)
{
    if (isEmpty(CQ))
        cout << "Queue is empty!" << endl;
    else
        cout << "Rear element: " << CQ->array[CQ->rear] << endl;
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
        if (i == CQ->rear)
            break;
        if (i == SIZE - 1)
            i = 0;
        else
            i = i + 1;
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
            enCqueue(&CQ, val);
            displayQueue(&CQ); // show updated queue
            break;
        case 2:
            deCqueue(&CQ);
            displayQueue(&CQ); // show updated queue
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
            if (isEmpty(&CQ)) cout << "Queue is empty." << endl;
            else cout << "Queue is not empty." << endl;
            break;
        case 7:
            if (isFull(&CQ)) cout << "Queue is full." << endl;
            else cout << "Queue is not full." << endl;
            break;
        case 8:
            displayQueue(&CQ);
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