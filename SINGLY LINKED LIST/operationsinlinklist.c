#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int info;
    struct Node *next;
};
struct SinglyLinkedList
{
    struct Node *head;
};
struct SinglyLinkedList *createList()
{
    struct SinglyLinkedList *list = (struct SinglyLinkedList *)malloc(sizeof(struct
                                                                             SinglyLinkedList));
    list->head = NULL;
    return list;
}
void insert_at_front(struct SinglyLinkedList *list, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = list->head;
    list->head = newNode;
}
void insert_at_end(struct SinglyLinkedList *list, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = NULL;
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    struct Node *lastNode = list->head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}
void insert_in_order(struct SinglyLinkedList *list, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    if (list->head == NULL || list->head->info >= info)
    {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    struct Node *current = list->head;
    while (current->next != NULL && current->next->info < info)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void delete_first(struct SinglyLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    struct Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
}
void delete_before_position(struct SinglyLinkedList *list, int position)
{
    if (position <= 1)
    {
        printf("Position must be greater than 1.\n");
        return;
    }
    if (list->head == NULL)
    {
        printf("List is empty. No nodes to delete.\n");
        return;
    }
    struct Node *current = list->head;
    if (position == 2)
    {
        list->head = list->head->next;
        free(current);
        return;
    }
    struct Node *prev = NULL;
    int count = 1;
    while (current != NULL && count < position - 1)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (prev == NULL || current == NULL)
    {
        printf("Position is out of bounds.\n");
        return;
    }
    prev->next = current;
    free(current);
}
void delete_after_position(struct SinglyLinkedList *list, int position)
{
    struct Node *current = list->head;
    int count = 1;
    while (current != NULL && count < position)
    {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL)
    {
        printf("No node exists after this position.\n");
        return;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}
void display(struct SinglyLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct SinglyLinkedList *linkedList = createList();
    int choice, info, position;
    // Default code
    printf("Practial-3\n");
    printf("Enrollment NO. :230130107052 \n");
    printf("Krina Jain\n");
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a node before specified position\n");
        printf("6. Delete a node after specified position\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &info);
            insert_at_front(linkedList, info);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &info);
            insert_at_end(linkedList, info);
            break;
        case 3:
            printf("Enter value to insert in order: ");
            scanf("%d", &info);
            insert_in_order(linkedList, info);
            break;
        case 4:
            delete_first(linkedList);
            break;
        case 5:
            printf("Enter position to delete before: ");
            scanf("%d", &position);
            delete_before_position(linkedList, position);
            break;
        case 6:
            printf("Enter position to delete after: ");
            scanf("%d", &position);
            delete_after_position(linkedList, position);
            break;
        case 7:
            display(linkedList);
            break;
        case 8:
            printf("Exiting...\n");
            free(linkedList); // Free the linked list memory
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}