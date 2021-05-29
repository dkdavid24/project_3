//
// Created by dkdav on 2021-05-25.
//

#include "name.h"

Name createName(const char *firstName, const char *lastName) {
    Name res;
    res.firstName = (char *) calloc(strlen(firstName) + 1, sizeof(char));
    res.lastName = (char *) calloc(strlen(lastName) + 1, sizeof(char));
    strcpy(res.firstName, firstName);
    strcpy(res.lastName, lastName);
    return res;
}

Name emptyName() {
    Name res;
    res.lastName = NULL;
    res.firstName = NULL;
    return res;
}

void setName(Name *dest, Name src) {
    dest->firstName = (char *) calloc(strlen(src.firstName) + 1, sizeof(char));
    dest->lastName = (char *) calloc(strlen(src.lastName) + 1, sizeof(char));
    strcpy(dest->firstName, src.firstName);
    strcpy(dest->lastName, src.lastName);
}

int compareName(Name name1, Name name2) {
    if (strcmp(name1.lastName, name2.lastName) == 0) {
        return strcmp(name1.firstName, name2.firstName);
    }
    return strcmp(name1.lastName, name2.lastName);
}

/** for qsort */
int compareNamePtr(const void *ptr1, const void *ptr2) {
    Name name1 = *(Name *) ptr1;
    Name name2 = *(Name *) ptr2;
    if (strcmp(name1.lastName, name2.lastName) == 0) {
        return strcmp(name1.firstName, name2.firstName);
    }
    return strcmp(name1.lastName, name2.lastName);
}

char *nameToStr(Name name) {
    char *res = (char *) calloc(strlen(name.firstName) + 1 + strlen(name.lastName + 1), sizeof(char));
    strcpy(res, name.firstName);
    res[strlen(name.firstName)] = ' ';
    strcpy(res + 1 + strlen(name.firstName), name.lastName);
    res[strlen(name.firstName) + 1 + strlen(name.lastName)] = '\0';
    return res;
}

void freeName(Name name) {
    free(name.firstName);
    free(name.lastName);
}
