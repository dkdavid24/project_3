#include "utils/name.h"
#include "utils/time_utils.h"

int main() {
    Array array;
    Root *root;
    hash hashTable;
    Heap *heap;
    List *list;
    for (dataStructures ds = ARRAY; ds <= LINKED_LIST; ds++) {
        printf("%s:\n", dataStructureToStr(ds));
        printf("Time to insert: %lf\n",
               timeToInsert("input.txt", ds, &array, &hashTable, &root, &heap, &list));
        printf("Time to search: %lf\n",
               timeToSearch("Kereses.txt", ds, &array, &hashTable, &root, &heap, &list));
        printf("Time to delete: %lf\n",
               timeToDelete("Torles.txt", ds, &array, &hashTable, &root, &heap, &list));
        printf("\n");
    }
    return 0;
}
