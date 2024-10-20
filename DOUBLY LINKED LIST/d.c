#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
// Function to create a new node
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
// Function to delete a node before a specified position
struct Node *deleteBeforePos(struct Node *head, int pos)
{
    struct Node *curr = head;
    int i;
    // Traverse to the node at the given position
    for (i = 1; curr != NULL && i < pos; ++i)
    {
        curr = curr->next;
    }
    if (curr == NULL || curr->prev == NULL)
    {
        printf("Invalid position or no node to delete before.\n");
        return head;
    }
    // Update pointers to skip the node to be deleted
    curr->prev->next = curr->next;
    if (curr->next != NULL)
    {
        curr->next->prev = curr->prev;
    }
    // Deallocate memory for the deleted node
    free(curr);
    return head;
}
// Function to display the doubly linked list
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
    printf("Enrollment no. :230130107o52\n ");
    printf("Krina Jain\n");
    struct Node *head = NULL;
    int value, position;
    // Inserting elements at the end
    head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;
    // Display the list before deletion
    display(head);
    // for the position to delete before
    printf("Enter the position to delete before: ");
    scanf("%d", &position);
    // Delete the node before the specified position
    head = deleteBeforePos(head, position);
    display(head);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
