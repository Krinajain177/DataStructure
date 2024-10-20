#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
// Function to enqueue an element
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        // First element in the queue
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
// Function to dequeue an element
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    free(temp);
}
// Function to peek at the front element
int peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return -1; // Return a sentinel value
    }
    return front->data;
}
// Function to display the queue
void display()
{
    struct Node *current = front;
    printf("Queue: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    printf("Practical 3.3\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Krina Jain\n");
    int choice, value;
    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            printf("Element removed:%d\n", value);
            break;
        case 3:
            value = peek();
            if (value != -1)
                printf("Front element: %d\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
