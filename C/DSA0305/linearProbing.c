#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 10

typedef enum {
    EMPTY,
    OCCUPIED,
    DELETED
} SlotStatus;

typedef struct {
    int key;
    int value;
    SlotStatus status;
} HashTableEntry;

HashTableEntry hashTable[TABLE_SIZE];

// helper functions 

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].value = -1;

        hashTable[i].status = EMPTY;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int probes = 0;

    while (probes < TABLE_SIZE) {
        if (hashTable[hashIndex].status == EMPTY || hashTable[hashIndex].status == DELETED) {
            hashTable[hashIndex].key = key;
            hashTable[hashIndex].value = value;
            hashTable[hashIndex].status = OCCUPIED;
            printf("Inserted (%d, %d) at index %d\n", key, value, hashIndex);
            return;
        } else if (hashTable[hashIndex].key == OCCUPIED && hashTable[hashIndex].key == key) {
            hashTable[hashIndex].value = value;
            printf("Updated (%d, %d) at index %d\n", key, value, hashIndex);
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        probes++;
        if (hashIndex == originalIndex) {
            printf("Hash table is full, cannot insert (%d, %d)\n", key, value);
            return;
        }
    }
    printf("Hash table is full, cannot insert (%d, %d)\n", key, value);
}

int search(int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int probes = 0;
    
    while(probes < TABLE_SIZE) {
        if (hashTable[hashIndex].status == EMPTY) {
            printf("Key %d not found\n", key);
            return -1;
        } 
        if (hashTable[hashIndex].status == OCCUPIED && hashTable[hashIndex].key == key) {
            printf("Found key %d with value %d at index %d\n", key, hashTable[hashIndex].value, hashIndex);
            return hashTable[hashIndex].value;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        probes++;
    }
    printf("Key %d not found\n", key);
    return -1;
}

void delete(int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int probes = 0;

    while (probes < TABLE_SIZE) {
        if (hashTable[hashIndex].status == EMPTY) {
            printf("Key %d not found for deletion\n", key);
            return;
        }
        if (hashTable[hashIndex].status == OCCUPIED && hashTable[hashIndex].key == key) {
            hashTable[hashIndex].status = DELETED;
            printf("Deleted key %d from index %d\n", key, hashIndex);
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        probes++;
    }
    printf("Key %d not found for deletion\n", key);
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].status == OCCUPIED) {
            printf("Index %d: (%d, %d)\n", i, hashTable[i].key, hashTable[i].value);
        } else if (hashTable[i].status == DELETED) {
            printf("Index %d: DELETED\n", i);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}

int main() {
    initTable();
    
    insert(1, 10);
    insert(2, 20);
    insert(12, 30);
    insert(22, 40);
    insert(32, 50);
    
    display();
    
    search(12);
    search(99);
    
    delete(12);
    delete(99);
    
    display();
    
    return 0;
}