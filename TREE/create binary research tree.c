#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Definition of the structure for a node in the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
// Function to search for a value in the BST
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}
// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
// Main function
int main()
{
    struct Node *root = NULL;
    int choice, value;
    // Default code
    printf("Practial-6\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina Jain\n");
    printf("6.1 Write a program which create binary search tree. \n");
    do
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value\t");
        printf("2. Search for a value\t");
        printf("3. Display in-order traversal\t");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d inserted successfully.\n", value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct Node *searchResult = search(root, value);
            if (searchResult != NULL)
            {
                printf("Found %d in the BST.\n", searchResult->data);
            }
            else
            {
                printf("%d not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("In-order traversal of the BST: ");
            inOrderTraversal(root);
            printf("\n");
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