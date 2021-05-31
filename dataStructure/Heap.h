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
    int capacity;

}Heap;

Heap* createHeap(int);
Heap* insertInHeap(Heap*,Name);
Heap* deleteFromHeap(Heap*,Name);
bool searchInHeap(Heap*,Name);
void up(Heap*,int);
void down(Heap*,int);
int getHeapElement(Heap*,Name);
void printHeap(Heap*);

#endif //PROJECT_3_HEAP_H
