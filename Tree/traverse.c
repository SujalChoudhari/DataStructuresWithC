#include <stdlib.h>
#include <stdio.h>

#define nullptr NULL
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
} Node;

void makeLeftChild(Node *parent, Node *child)
{
    parent->left = child;
}

void makeRightChild(Node *parent, Node *child)
{
    parent->right = child;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = value;

    return newNode;
}

void inOrderTraversal(Node *root)
{

    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node *root)
{

    if (root != nullptr)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node *root)
{

    if (root != nullptr)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        root = createNode(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}
Node *addElement(Node *root)
{
    while (1)
    {
        int value;
        printf("\nEnter Value:");
        scanf("%d", &value);

        // Insert
        if (value != -1)
            root = insert(root, value);
        else
            return root;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = createNode(0);

    Node *n1 = createNode(1);
    Node *n2 = createNode(2);
    Node *n3 = createNode(3);
    Node *n4 = createNode(4);
    Node *n5 = createNode(5);
    Node *n6 = createNode(6);
    Node *n7 = createNode(7);
    Node *n8 = createNode(8);

    makeLeftChild(root, n1);
    makeRightChild(root, n2);

    makeLeftChild(n1, n3);
    makeRightChild(n1, n4);

    makeLeftChild(n2, n5);
    makeRightChild(n2, n6);

    makeLeftChild(n3, n7);
    makeRightChild(n5, n8);

    /* My Tree
             0
            /  \
           1    2
          / \   / \
         3   4 5   6
        /       \
       7         8
    */

    printf("INORDER: ");
    inOrderTraversal(root);
    printf("\n");

    printf("PREORDER: ");
    preOrderTraversal(root);
    printf("\n");

    printf("POSTORDER: ");
    postOrderTraversal(root);
    printf("\n");

    Node *newTree = nullptr;
    newTree = addElement(newTree);

    printf("INORDER: ");
    inOrderTraversal(newTree);
    printf("\n");

    printf("PREORDER: ");
    preOrderTraversal(newTree);
    printf("\n");

    printf("POSTORDER: ");
    postOrderTraversal(newTree);
    printf("\n");
}
