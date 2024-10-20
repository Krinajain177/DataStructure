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
// Function to insert a new node at the end of the circular linked list
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head; // Point to itself to make it circular
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Make it circular
    }
}
// Function to delete a node after a specified position
void deleteAfter(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is empty. No node to delete.\n");
        return;
    }
    struct Node *temp = *head;
    int count = 1;
    // Traverse to the specified position
    while (count < position && temp->next != *head)
    {
        temp = temp->next;
        count++;
    }
    // If the specified position is out of range
    if (count < position)
    {
        printf("Position out of range.\n");
        return;
    }
    // Delete the node after the specified position
    struct Node *nodeToDelete = temp->next;
    if (nodeToDelete == *head)
    {
        printf("There is no node after the specified position to delete.\n");
        return;
    }
    temp->next = nodeToDelete->next; // Link to the node after the one to be deleted
    free(nodeToDelete);              // Free the memory of the deleted node
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
    printf("5.1(d) Delete a node after specified position.\n");
    do
    {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert a node at the end\t");
        printf("2. Delete a node after a specified position\t");
        printf("3. Display the list\t");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            printf("%d inserted successfully.\n", value);
            break;
        case 2:
            printf("Enter position to delete after: ");
            scanf("%d", &position);
            deleteAfter(&head, position);
            printf("Node deleted successfully after position %d.\n", position);
            break;
        case 3:
            printf("Circular Linked List: ");
            display(head);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
