#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left_child;
    struct node *right_child;
};

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left_child);
    printf("%d ->", root->item);
    inorderTraversal(root->right_child);
}

// Preorder traversal
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->item);
    preorderTraversal(root->left_child);
    preorderTraversal(root->right_child);
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left_child);
    postorderTraversal(root->right_child);
    printf("%d ->", root->item);
}

// Create a new Node
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left_child = NULL;
    newNode->right_child = NULL;

    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root,int value)
{
    root->left_child = createNode(value);
    return root->left_child;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
    root->right_child = createNode(value);
    return root->right_child;
}

void setup()
{
    struct node *root = createNode(0);
    insertLeft(root->left_child, -90);
    insertRight(root->right_child, 90);
    inorderTraversal(root);
}