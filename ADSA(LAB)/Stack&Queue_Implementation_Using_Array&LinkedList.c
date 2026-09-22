#include <stdio.h>

#define SIZE 5

int queue[SIZE];

int front = -1;
int rear = -1;


// ENQUEUE
void ENQUEUE(int value)
{
    // Queue Overflow
    if (rear == SIZE - 1)
    {
        printf("Queue is Overflow\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
    }

    rear++;

    queue[rear] = value;

    printf("%d is inserted into queue\n", value);
}


// DEQUEUE
void DEQUEUE()
{
    // Queue Underflow
    if (front == -1 || front > rear)
    {
        printf("Queue is Underflow\n");
        return;
    }

    printf("%d is deleted from queue\n", queue[front]);

    front++;

    // Queue becomes empty
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}


// PEEK
void PEEK()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element is: %d\n", queue[front]);
}


// DISPLAY
void DISPLAY()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}


// MAIN
int main()
{
    ENQUEUE(10);
    ENQUEUE(20);
    ENQUEUE(30);
    ENQUEUE(40);

    DISPLAY();

    PEEK();

    DEQUEUE();

    DISPLAY();

    return 0;
}