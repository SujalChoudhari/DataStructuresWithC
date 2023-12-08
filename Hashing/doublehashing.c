#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)calloc(1, sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

int hashFunction(int key, int size) {
    return key % size;
}

int hashFunction2(int key) {
    return (key % 7) + 1;
}

int doubleHash(int key, int attempt, int size) {
    return (hashFunction(key, size) + attempt * hashFunction2(key)) % size;
}

void insertKey(struct Node* hashTable, int key, int size) {
    int attempt = 0;
    int index;

    do {
        index = doubleHash(key, attempt, size);

        if (hashTable[index].data == 0) {
            hashTable[index].data = key;
            return;
        }

        attempt++;
    } while (attempt < size);

    printf("Error: Unable to insert key %d. Hash table is full.\n", key);
}

void printHashTable(struct Node* hashTable, int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: [%d]\n", i, hashTable[i].data);
    }
}

int main() {
    int tableSize;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tableSize);

    struct Node* myHashTable = (struct Node*)calloc(tableSize, sizeof(struct Node));

    int numKeys;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    for (int i = 0; i < numKeys; i++) {
        int key;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &key);
        insertKey(myHashTable, key, tableSize);
    }

    printf("\nTable after Double Hashing:\n");
    printHashTable(myHashTable, tableSize);

    return 0;
}
