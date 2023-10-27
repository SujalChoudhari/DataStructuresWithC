#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insert_at_beginning(Node *head, int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
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

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    return head;
}

Node *insert_at_position(Node *head, int value, int position)
{
    Node *newNode = createNode(value);
    if (head == NULL && position > 1)
    {
        printf("Invalid position. List is currently empty.\n");
        return head;
    }
    if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *ptr = head;
        int count = 1;
        while (count < position - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        if (ptr == NULL)
        {
            printf("Invalid position. The list is not long enough.\n");
        }
        else
        {
            newNode->next = ptr->next;
            newNode->prev = ptr;
            if (ptr->next != NULL)
            {
                ptr->next->prev = newNode;
            }
            ptr->next = newNode;
        }
    }
    return head;
}

Node *delete_at_beginning(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
    }
    else
    {
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
    }
    return head;
}

Node *delete_at_end(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}

Node *delete_at_position(Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
    }
    else if (position == 1)
    {
        head = delete_at_beginning(head);
    }
    else
    {
        Node *ptr = head;
        int count = 1;
        while (count < position && ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        if (ptr == NULL)
        {
            printf("Invalid position. The list is not long enough.\n");
        }
        else if (ptr->next == NULL)
        {
            head = delete_at_end(head);
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
    return head;
}

void display_dll(Node *head)
{
    Node *ptr = head;

    if (head == NULL)
    {
        printf("\nThe List is Empty\n\n");
        return;
    }

    printf("The List is: ");
    while (ptr->next != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);

    printf("\n");
}

void dll_menu()
{
    Node *head = NULL;

    while (1)
    {
        int choice = 0;
        printf("\nDoubly Linked List:\n");
        printf("1. Display List\n");
        printf("2. Insert At Beginning\n");
        printf("3. Insert At End\n");
        printf("4. Insert At Position\n");
        printf("5. Delete At Beginning\n");
        printf("6. Delete At End\n");
        printf("7. Delete At Position\n");
        printf("8. Exit\n");

        scanf("%d", &choice);
        int value = 0;
        int position = 0;
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
        case 4:
            printf("\nEnter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            head = insert_at_position(head, value, position);
            break;
        case 5:
            head = delete_at_beginning(head);
            break;
        case 6:
            head = delete_at_end(head);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &position);
            head = delete_at_position(head, position);
            break;
        case 8:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

int main()
{
    dll_menu();
    return 0;
}
