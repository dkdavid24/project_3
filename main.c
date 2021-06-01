#include "utils/name.h"
#include "utils/time_utils.h"

int main() {
    Array array;
    Root *root;
    hash hashTable;
    Heap *heap;
    List *list;
    printf("Time: %lf\n", timeToInsert("input.txt", ARRAY, &array, &hashTable, &root, &heap, &list));
    listName(&array);
    return 0;
}
