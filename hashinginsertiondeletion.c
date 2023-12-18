#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int data) {
    int index = hashFunction(data);
    struct Node* newNode = createNode(data);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int key) {
    int index = hashFunction(key);
    struct Node* currentNode = hashTable[index];
    struct Node* prevNode = NULL;

    while (currentNode != NULL && currentNode->data != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Key not found, deletion failed.\n");
        return;
    }

    if (prevNode == NULL) {
        hashTable[index] = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    free(currentNode);
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("[%d]: ", i);
        struct Node* currentNode = hashTable[i];
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table buckets to NULL
    for (int i = 0; i < SIZE; ++i) {
        hashTable[i] = NULL;
    }

    insert(5);
    insert(15);
    insert(25);
    insert(12);
    insert(22);

    displayHashTable();

    deleteNode(15);
    deleteNode(12);

    displayHashTable();

    return 0;
}

