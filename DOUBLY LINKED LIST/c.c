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
// Function to delete the last node
void deleteLastNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        // Only one node in the list
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *current = *head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
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
    // Delete the last node
    deleteLastNode(&head);
    display(head);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
