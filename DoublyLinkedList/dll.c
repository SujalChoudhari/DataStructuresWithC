#include <stdio.h>
#include <stdlib.h>
#define nullptr 0x0

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

Node *insert_at_beginning(Node *head, int value)
{
    Node *newNode = createNode(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node *insert_at_end(Node *head, int value)
{
    Node *newNode = createNode(value);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        // got end element
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    return head;
}

void display_dll(Node *head)
{
    Node *ptr = head;

    if (head == nullptr)
    {
        printf("\n\tLIST IS EMPTY!!!!!");
        return;
    }

    while (ptr != nullptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

Node* insert_at_position(Node* head,int value, int pos){
    if(head == nullptr) {
        printf("\n\tLIST IS EMPTY!!!!");
        return;
    }
    if(pos == 1){
        return insert_at_beginning(head,value);
    }
    else {
        Node* ptr;
        // while()
    }
}

void dll_menu()
{
    while (1)
    {
        Node *head;

        int choice = 0;
        printf("Doubly Linked List:\n");
        printf("1. Display List\n");
        printf("2. Insert At Beginning\n");
        printf("3. Insert At End\n");

        scanf("%d", &choice);
        int value = 0;
        switch (choice)
        {
        case 1:
            display_dll(head);
            break;
        case 2:
            printf("\nEnter value: ");
            scanf("%d", &value);
            head = insert_at_beginning(head, value);
            break;
        case 3:
            printf("\nEnter value: ");
            scanf("%d", &value);
            head = insert_at_end(head, value);
            break;
        default:
            return;
        }
    }
}

void main()
{
    dll_menu();
}