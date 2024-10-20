#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Definition of the structure for a node in the circular linked list
struct Node
{
    int data;
    struct Node *next;
};
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a new node before a specified position
void insertBefore(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        if (position == 1)
        {
            *head = newNode;
            newNode->next = *head; // Point to itself to make it circular
        }
        else
        {
            printf("Position out of range. List is empty.\n");
        }
        return;
    }
    struct Node *temp = *head;
    int count = 1;
    // If inserting before the head
    if (position == 1)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode; // Update head
        return;
    }
    // Traverse to the position
    while (count < position - 1 && temp->next != *head)
    {
        temp = temp->next;
        count++;
    }
    // If position is out of range
    if (count < position - 1)
    {
        printf("Position out of range.\n");
        return;
    }
    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}
// Function to display the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data); // To indicate circularity
}
// Main function
int main()
{
    struct Node *head = NULL;
    int choice, value, position;
    // Default code
    printf("Practial-5\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina Jain\n");
    printf("5.1(b) Insert a node before specified position.\n");
    do
    {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert a node before a specified position\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert before: ");
            scanf("%d", &position);
            insertBefore(&head, value, position);
            printf("%d inserted before position %d successfully.\n", value, position);
            break;
        case 2:
            printf("Circular Linked List: ");
            display(head);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
