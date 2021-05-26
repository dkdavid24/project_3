//
// Created by dkdav on 2021-05-25.
//

#ifndef PROJECT_3_NAME_H
#define PROJECT_3_NAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *firstName;
    char *lastName;
} Name;

Name createName(const char *, const char *);

int compareName(Name, Name);

/** for qsort */
int compareNamePtr(const void *, const void *);

char *nameToStr(Name);

void freeName(Name);

#endif //PROJECT_3_NAME_H
