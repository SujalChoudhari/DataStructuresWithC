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

Node *makeTree(int parentValue, int dir)
{

    int value = -1;
    if (dir != -1)
        printf("Enter %s of %d\n>>> ", dir ? "right" : "left", parentValue);
    else
        printf("Enter Value of root node of parent %d\n>>> ", parentValue);

    scanf("%d", &value);
    if (value == -1)
        return nullptr;

    Node *root = createNode(value);

    root->left = makeTree(value, 0);
    root->right = makeTree(value, 1);

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



    Node *newTree = makeTree(0, -1);

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
