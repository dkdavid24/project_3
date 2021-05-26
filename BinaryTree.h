//
// Created by Robi on 2021. 05. 25..
//

#ifndef PROJECT_3_BINARYTREE_H
#define PROJECT_3_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "name.h"

typedef struct Root{
    Name name;
    struct Root* right;
    struct Root* left;

}Root;

Root* create();
Root* insert(Root*,Name);

#endif //PROJECT_3_BINARYTREE_H
