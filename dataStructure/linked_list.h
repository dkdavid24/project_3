//
// Created by dkdav on 2021-05-26.
//

#ifndef PROJECT_3_LINKED_LIST_H
#define PROJECT_3_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/name.h"


typedef struct NODE_LIST {
    Name data;
    struct NODE_LIST *next;
} List;

List *createListNode(Name);

void insertList(List **, Name);

bool inList(List *, Name);

/** not tested */
List *getList(List *, Name);

void deleteFromList(List **, Name);

void utilPrintList(List *);


#endif //PROJECT_3_LINKED_LIST_H
