//
// Created by Robi on 2021. 05. 25..
//

#ifndef PROJECT_3_BINARYTREE_H
#define PROJECT_3_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../name.h"

typedef struct Root{
    Name name;
    struct Root* right;
    struct Root* left;

}Root;

Root* createRoot();
Root* insertInTree(Root*,Name);
bool searchInTree(Root* root,Name);
Root* deleteFromTree(Root*,Name);
Root* first(Root*);
void printTree(Root*);

#endif //PROJECT_3_BINARYTREE_H
