#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertKey(struct Node **hashTable, int key, int size)
{
    int index = (3 * key + 1) % size;

    if (hashTable[index] == NULL)
    {
        hashTable[index] = createNode(key);
    }
    else
    {
        struct Node *newNode = createNode(key);
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void printHashTable(struct Node **hashTable, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Index %d: ", i);
        struct Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("[%d]->", current->data);
            current = current->next;
        }
        printf("[ / ]\n");
    }
}

int main()
{
    int tableSize;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tableSize);

    struct Node **myHashTable = (struct Node **)calloc(tableSize, sizeof(struct Node *));

    int numKeys;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    for (int i = 0; i < numKeys; i++)
    {
        int key;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &key);
        insertKey(myHashTable, key, tableSize);
    }

    printf("\nTable after CHaining:\n");
    printHashTable(myHashTable, tableSize);

    return 0;
}
