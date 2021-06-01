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
            *array = createArray(numEntries);
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
            *heap = createHeap(numEntries);
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
        //fscanf(fin, "%[^ ] %[^\n]\n", firstName, lastName);
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
            default: {
                printf("Unknown type: %i\n", type);
                return 0;
            }
        }
    }
    clock_t end = clock();
    fclose(fin);
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

double timeToSearch(const char *path, dataStructures type, Array *array, hash *hashTable, Root **binaryTree,
                    Heap **heap, List **linkedList) {
    int numEntries = numberOfEntries(path);

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
                findName(array, createName(firstName, lastName));
                break;
            }
            case HASH: {
                searchHash(hashTable, createName(firstName, lastName));
                break;
            }
            case BINARY_TREE: {
                searchInTree(*binaryTree, createName(firstName, lastName));
                break;
            }
            case HEAP: {
                searchInHeap(*heap, createName(firstName, lastName));
                break;
            }
            case LINKED_LIST: {
                inList(*linkedList, createName(firstName, lastName));
                break;
            }
            default: {
                printf("Unknown type: %i\n", type);
                return 0;
            }
        }
    }

    clock_t end = clock();
    fclose(fin);
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

double timeToDelete(const char *path, dataStructures type, Array *array, hash *hashTable, Root **binaryTree,
                    Heap **heap, List **linkedList) {
    int numEntries = numberOfEntries(path);

    FILE *fin = fopen(path, "rt");
    if (!fin) {
        printf("\nMissing file: %s\n", path);
    }
    char firstName[nameLength], lastName[nameLength];
    clock_t begin = clock();
    for (int i = 0; i < numEntries; i++) {
        fscanf(fin, "%[^,],%[^\n]\n", firstName, lastName);
        //fscanf(fin, "%[^ ] %[^\n]\n", firstName, lastName);
        switch (type) {
            case ARRAY: {
                deleteName(array, createName(firstName, lastName));
                break;
            }
            case HASH: {
                deleteHash(hashTable, createName(firstName, lastName));
                break;
            }
            case BINARY_TREE: {
                deleteFromTree(*binaryTree, createName(firstName, lastName));
                break;
            }
            case HEAP: {
                deleteFromHeap(*heap, createName(firstName, lastName));
                break;
            }
            case LINKED_LIST: {
                deleteFromList(linkedList, createName(firstName, lastName));
                break;
            }
            default: {
                printf("Unknown type: %i\n", type);
                return 0;
            }
        }
    }

    clock_t end = clock();
    fclose(fin);
    return (double) (end - begin) / CLOCKS_PER_SEC;
}

char *dataStructureToStr(dataStructures ds) {
    switch (ds) {
        case ARRAY:
            return "array";
        case BINARY_TREE:
            return "binary tree";
        case HASH:
            return "hash table";
        case HEAP:
            return "heap";
        case LINKED_LIST:
            return "linked";
        default:
            return "Unknown";
    }
}
