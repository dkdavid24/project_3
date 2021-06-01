#include "utils/name.h"
#include "utils/time_utils.h"

int main() {
    Array array;
    Root *root;
    hash hashTable;
    Heap *heap;
    List *list;
    dataStructures DATA_STRUCTURE = LINKED_LIST;
    printf("Time to insert: %lf\n", timeToInsert("input.txt", DATA_STRUCTURE, &array, &hashTable, &root, &heap, &list));
    printf("Time to search: %lf\n",
           timeToSearch("Kereses.txt", DATA_STRUCTURE, &array, &hashTable, &root, &heap, &list));
    printf("Time to delete: %lf\n",
           timeToDelete("Torles.txt", DATA_STRUCTURE, &array, &hashTable, &root, &heap, &list));
    return 0;
}
