//
// Created by Robi on 2021. 05. 25..
//

#ifndef PROJECT_3_HEAP_H
#define PROJECT_3_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../utils/name.h"

typedef struct{
    Name* names;
    int size;

}Heap;

Heap* createHeap();
Heap* insertInHeap(Heap*,Name);
Heap* deleteFromHeap(Heap*,Name);
int searchInHeap(Heap*,Name);
void up(Heap*,int);
void down(Heap*,int);
void printHeap(Heap*);

#endif //PROJECT_3_HEAP_H
