#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

// Hash Table structure
typedef struct {
    int key;
    int value;
} HashTable;

HashTable hashTable[SIZE];

// Initialize Hash Table
void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].key = -1;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert element into Hash Table using linear probing
void insert(int key, int value) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash Table is full. Cannot insert.\n");
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Display Hash Table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    initHashTable();

    int numElements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        int key, value;
        printf("Enter key and value for element %d: ", i + 1);
        scanf("%d %d", &key, &value);
        insert(key, value);
    }

    display();

    return 0;
}
