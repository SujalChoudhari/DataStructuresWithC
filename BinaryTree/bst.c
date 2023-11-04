#include <stdio.h>
#include <stdlib.h>
#define nullptr NULL

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int data;

} Node;

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
    int value;
    printf("\nEnter Value:");
    scanf("%d", &value);

    // Insert
    root = insert(root, value);
    return root;
}

void kthLargestFinder(Node *root, int k, int *count)
{
    // use reverse traversal inorder approach

    if (root == nullptr || k < *count)
    {
        return;
    }

    // Right
    kthLargestFinder(root->right, k, count);
    // Self
    (*count)++;
    if (*count == k)
    {
        printf("%dth largest element is %d\n\n", k, root->data);
    }

    // Left
    kthLargestFinder(root->left, k, count);
}

void kthLargestElement(Node *root)
{
    int k = 0;
    printf("\nEnter k: ");
    scanf("%d", &k);
    int count = 0;
    kthLargestFinder(root, k, &count);
}

int balancedChecker(Node *head)
{

    if (head != nullptr)
    {
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    Node *root = nullptr;
    while (1)
    {
        int choice = 0;
        printf("1. Enter Element\n");
        printf("2. Display Inorder\n");
        printf("3. Find kth Element\n");
        printf("4. Is Balanced\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = addElement(root);
            break;
        case 2:
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            kthLargestElement(root);
            break;
        case 4:
            balancedChecker(root);
            break;
        default:
            return 0;
        }
    }
    return 0;
}
