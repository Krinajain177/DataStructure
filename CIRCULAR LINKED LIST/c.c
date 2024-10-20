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
// Function to delete the first node of the circular linked list
void deleteFirstNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty. No node to delete.\n");
        return;
    }
    struct Node *temp = *head;
    // If there's only one node in the list
    if (temp->next == *head)
    {
        free(temp);
        *head = NULL; // List becomes empty
    }
    else
    {
        struct Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = temp->next; // Update last node's next
        *head = temp->next;      // Update head to the next node
        free(temp);              // Free the old head
    }
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
    int choice, value;
    // Default code
    printf("Practial-5\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina Jain\n");
    printf("5.1(c) Delete a first node of the linked list. \n");
    do
    {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert a node at the end\t");
        printf("2. Delete the first node\t");
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
            deleteFirstNode(&head);
            printf("First node deleted successfully.\n");
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
