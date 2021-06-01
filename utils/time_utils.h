//
// Created by dkdav on 2021-05-29.
//

#ifndef PROJECT_3_TIME_UTILS_H
#define PROJECT_3_TIME_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "name.h"
#include "../dataStructure/array.h"
#include "../dataStructure/hash.h"
#include "../dataStructure/BinaryTree.h"
#include "../dataStructure/Heap.h"
#include "../dataStructure/linked_list.h"

typedef enum {
    ARRAY = 0,
    HASH,
    BINARY_TREE,
    HEAP,
    LINKED_LIST
} dataStructures;

int numberOfEntries(const char *);

double timeToInsert(const char *, dataStructures, Array *, hash*, Root **, Heap **, List **);

double timeToSearch(const char *, dataStructures, Array *, hash*, Root **, Heap **, List **);

double timeToDelete(const char *, dataStructures, Array *, hash*, Root **, Heap **, List **);


#endif //PROJECT_3_TIME_UTILS_H
