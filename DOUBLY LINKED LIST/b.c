#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the end
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        // List is empty, newNode becomes the head
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
void display(struct Node *head)
{
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    printf("Practical 4.1(b)\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Krina Jain\n");
    struct Node *head = NULL;
    int value;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);
    printf("Enter a value to insert at the end: ");
    scanf("%d", &value);
    insertAtEnd(&head, value);
    display(head);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}