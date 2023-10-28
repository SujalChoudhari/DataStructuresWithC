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

int main(int argc, char const *argv[])
{
    int size = 9;
    int inorder[] = {7, 3, 1, 4, 0, 5, 8, 2, 6};
    int postorder[] = {7, 3, 4, 1, 8, 5, 6, 2, 0};

    Node *tree = maketree(inorder, postorder, size, size - 1);
}

Node *maketree(int inorder[], int postorder[], int size, int rootIndex)
{
    int value = postorder[rootIndex];
    Node *root = createNode(value);

    int rootIndexInInOrder

    int* leftSubTree = (int*) calloc(sizeof int)

}
