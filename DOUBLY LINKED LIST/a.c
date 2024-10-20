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
// Function to insert a node at the front
void insertAtFront(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        // List is empty, newNode becomes the head
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void display(struct Node *head)
{
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    printf("Practical 4.1\n");
    printf("Enrollment no. :230130107052\n ");
    printf("Krina Jain");
    struct Node *head = NULL;
    int value;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    display(head);
    printf("Enter a value to insert at the front: ");
    scanf("%d", &value);
    insertAtFront(&head, value);
    display(head);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
