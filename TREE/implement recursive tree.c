#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}
struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}
int main()
{
    // Default code
    printf("Practial-6\n");
    printf("Enrollment NO. :- 230130107052\n");
    printf("Krina Jain\n");
    printf("6.2:Implement recursive tree traversing methods inorder, preorder and postorder traversal\n");
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    printf("\nInorder Traversal:\n");
    inorderTraversal(root);
    printf("\nPre-order Traversal:\n");
    preorderTraversal(root);
    printf("\nPost-order Traversal:\n");
    postorderTraversal(root);
    return 0;
}
