//
// Created by dkdav on 2021-05-26.
//

#ifndef PROJECT_3_LINKED_LIST_H
#define PROJECT_3_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "name.h"


typedef struct NODE {
    Name data;
    struct NODE *next;
} Node;

Node *createListNode(Name);

void insertList(Node **, Name);

bool inList(Node *, Name);

/** not tested */
Node *getList(Node *, Name);

void deleteFromList(Node **, Name);

void utilPrintList(Node *);


#endif //PROJECT_3_LINKED_LIST_H
