 #include <stdio.h>
#define SIZE 5

// Queue implementation using an array
struct Queue
{
    int itmes[SIZE];
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
    return (q->front == (q->rear + 1) % SIZE);
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
        printf("Queue is Overflow! Cannot insert %d\n", value);
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % SIZE;
        q->itmes[q->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

// Dequeue operation
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Underflow! Cannot delete\n");
    }
    else
    {
        int item = q->itmes[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Deleted -> %d\n", item);
    }
}

// Print the queue
void printQueue(struct Queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
        {
            printf("%d ", q->itmes[i]);
        }
        printf("%d ", q->itmes[i]);
        printf(" <- Rear\n");
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    printQueue(&q);

    enqueue(&q, 6);
    enqueue(&q, 7);
    printQueue(&q);

    return 0;
}