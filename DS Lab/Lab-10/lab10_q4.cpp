// Lab 10 - Q4: Queue using linked list
//
// Time complexity : create O(1), isEmpty O(1), isFull O(1), enqueue O(1),
//                   dequeue O(1), front/rear O(1), count O(n), display O(n)
// Auxiliary space : O(1) per operation (each enqueue allocates one node;
//                   the whole queue occupies O(n) space for n elements)
//
// Note: a linked queue has no fixed capacity. isFull() is true only when
// memory allocation fails.

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int INFO;
    Node *NEXT;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void createEmptyQueue(struct Queue *Q)
{
    Q->front = Q->rear = NULL; // NULL means queue is empty
}

bool isEmpty(struct Queue *Q)
{
    return (Q->front == NULL || Q->rear == NULL);
}

bool isFull(struct Queue *Q)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
        return true;
    free(temp);
    return false;
}

void enLqueue(struct Queue *Q, int Item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) // only when RAM is full
    {
        cout << "Queue Overflow: Out of memory!" << endl;
        return;
    }
    new_node->INFO = Item;
    new_node->NEXT = NULL;

    if (isEmpty(Q))
    {
        Q->front = Q->rear = new_node;
    }
    else
    {
        (Q->rear)->NEXT = new_node;
        Q->rear = new_node;
    }
    cout << "Enqueued successfully." << endl;
}

void deLqueue(struct Queue *Q)
{
    Node *temp;
    if (isEmpty(Q))
    {
        cout << "Queue Underflow: Queue is empty!" << endl;
        return;
    }
    int Item = (Q->front)->INFO;
    temp = Q->front;
    if (Q->rear == Q->front) // only one element
    {
        Q->front = NULL;
        Q->rear = NULL;
    }
    else
    {
        Q->front = (Q->front)->NEXT;
    }
    free(temp);
    cout << "Dequeued item: " << Item << endl;
}

void displayFront(struct Queue *Q)
{
    if (isEmpty(Q))
        cout << "Queue is empty!" << endl;
    else
        cout << "Front element: " << (Q->front)->INFO << endl;
}

void displayRear(struct Queue *Q)
{
    if (isEmpty(Q))
        cout << "Queue is empty!" << endl;
    else
        cout << "Rear element: " << (Q->rear)->INFO << endl;
}

void countElements(struct Queue *Q)
{
    int count = 0;
    Node *temp = Q->front;
    while (temp != NULL)
    {
        count++;
        temp = temp->NEXT;
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
    Node *temp = Q->front;
    while (temp != NULL)
    {
        cout << temp->INFO << " ";
        temp = temp->NEXT;
    }
    cout << endl;
}

void freeQueue(struct Queue *Q) // release all nodes before exiting
{
    Node *temp;
    while (Q->front != NULL)
    {
        temp = Q->front;
        Q->front = (Q->front)->NEXT;
        free(temp);
    }
    Q->rear = NULL;
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
            enLqueue(&Q, val);
            displayQueue(&Q); // show updated queue
            break;
        case 2:
            deLqueue(&Q);
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
            freeQueue(&Q);
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);

    return 0;
}