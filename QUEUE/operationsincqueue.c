#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
int circularQueue[size];
int front = -1;
int rear = -1;
void enqueue(int item)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue is full. Cannot enqueue more elements.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        circularQueue[rear] = item;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        printf("Dequeued element: %d\n", circularQueue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", circularQueue[rear]);
    }
}
int main()
{
    int choice, item;
    printf("Practical 2.2\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Krina Jain\n");
    while (1)
    {
        printf("\nCircular Queue Operations:\t1.Insert\t2.Delete\t3.Display\t4.Exit:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
