#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed. Stack is full.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}
// Function to peek at the top element
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value
    }
    return top->data;
}
// Function to display the stack
void display()
{
    struct Node *current = top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    int choice, value;
    printf("Practical 3.2\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Krina Jain\n");
    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            value = peek();
            if (value != -1)
                printf("Top element: %d\n", value);
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
