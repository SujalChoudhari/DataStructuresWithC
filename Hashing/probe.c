#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)calloc(1, sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

int linearProbe(int index, int size)
{
    return (index + 1) % size;
}

int quadraticProbe(int index, int size) {
    return (index + 1 * index + 1) % size;
}


void insertKey(struct Node *hashTable, int key, int size)
{
    int index = key % size;

    while (hashTable[index].data != 0)
    {
        index = quadraticProbe(index, size);
    }

    hashTable[index].data = key;
}

void printHashTable(struct Node *hashTable, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Index %d: [%d]\n", i, hashTable[i].data);
    }
}

int main()
{
    int tableSize;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tableSize);

    struct Node *myHashTable = (struct Node *)calloc(tableSize, sizeof(struct Node));

    for (int i = 0; i < tableSize; i++)
    {
        int key;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &key);
        insertKey(myHashTable, key, tableSize);
    }

    printf("\nTable after Linear Probing:\n");
    printHashTable(myHashTable, tableSize);

    return 0;
}
