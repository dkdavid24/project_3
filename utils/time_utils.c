//
// Created by dkdav on 2021-05-29.
//

#include "time_utils.h"

int numberOfEntries(const char *path) {
    FILE *fin = fopen(path, "rt");
    if (!fin) {
        printf("\nMissing file: %s\n", path);
    }
    int res = 0;
    char line[60];
    for (; fscanf(fin, "%[^\n]\n", line) != EOF; res++);
    fclose(fin);
    return res;
}

double
timeToInsert(const char *path, dataStructures type, Array *array, hash *hashTable, Root **binaryTree, Heap **heap,
             List **linkedList) {
    int numEntries = numberOfEntries(path);
    switch (type) {
        case ARRAY: {
            *array = createArray();
            break;
        }
        case HASH: {
            *hashTable = createTable(numEntries);
            break;
        }
        case BINARY_TREE: {
            *binaryTree = NULL;
            break;
        }
        case HEAP: {
            *heap = createHeap();
            break;
        }
        case LINKED_LIST: {
            *linkedList = NULL;
            break;
        }
        default:
            printf("Unknown type: %i\n", type);
            return 0;
    }
    FILE *fin = fopen(path, "rt");
    if (!fin) {
        printf("\nMissing file: %s\n", path);
    }
    char firstName[nameLength], lastName[nameLength];
    clock_t begin = clock();
    for (int i = 0; i < numEntries; i++) {
        fscanf(fin, "%[^,],%[^\n]\n", firstName, lastName);
        switch (type) {
            case ARRAY: {
                addName(array, createName(firstName, lastName));
                break;
            }
            case HASH: {
                insertTable(hashTable, createName(firstName, lastName));
                break;
            }
            case BINARY_TREE: {
                *binaryTree = insertInTree(*binaryTree, createName(firstName, lastName));
                break;
            }
            case HEAP: {
                *heap = insertInHeap(*heap, createName(firstName, lastName));
                break;
            }
            case LINKED_LIST: {
                insertList(linkedList, createName(firstName, lastName));
                break;
            }
        }
    }
    clock_t end = clock();
    fclose(fin);
    return (double) (end - begin) / CLOCKS_PER_SEC;
}