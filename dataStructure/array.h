//
// Created by Horvath on 2021. 05. 25..
//

#ifndef PROJECT_3_ARRAY_H
#define PROJECT_3_ARRAY_H
#include "../name.h"
#include <stdbool.h>
typedef struct arr{
    int count;
    int size;
    Name *names;
}Array;
Array createArray(int );
void addName(Array *,Name );
void deleteName(Array *,Name );
void listName(Array *res);
bool findName(Array *,Name );
#endif //PROJECT_3_ARRAY_H
