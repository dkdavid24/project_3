#include "utils/name.h"
#include "utils/time_utils.h"

int main() {
    Array array;
    Root *root;
    hash hashTable;
    Heap *heap;
    List *list;
    printf("Time: %lf\n", timeToInsert("input.txt", HASH, &array, &hashTable, &root, &heap, &list));
    listTable(&hashTable);
    printf("\n%i\n", searchHash(&hashTable, createName("test test", "test 6")));
    printf("\n%i\n", searchHash(&hashTable, createName("test test", "test 12")));
    deleteHash(&hashTable, createName("test test", "test 6"));
    printf("\n%i\n", searchHash(&hashTable, createName("test test", "test 6")));
    return 0;
}
