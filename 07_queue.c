#include <stdio.h>
#define SIZE 5

// Queue implementation using an array
struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue *q)
{
    return q->rear == SIZE - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot insert %d\n", value);
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation
int dequeue(struct Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        printf("Deleted %d\n", item);
        return item;
    }
}

// Display the queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);

    display(&q);

    return 0;
}
