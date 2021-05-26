//
// Created by Horvath on 2021. 05. 26..
//

#ifndef PROJECT_3_HASH_H
#define PROJECT_3_HASH_H
#include "name.h"
#include <stdbool.h>
typedef struct hashtable{
    Name *names;
    int currentSize;
    int capacity;
}hash;
hash createTable(int );
void insertTable(hash *, Name );
bool searchHash(hash *, Name );
void deleteHash(hash *,Name );
void listTable(hash *);
#endif //PROJECT_3_HASH_H
