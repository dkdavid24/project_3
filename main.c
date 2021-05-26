#include "name.h"
#include "array.h"
#include "hash.h"

int main() {
    Name name1 = createName("first", "last");
    Name name2 = createName("osvath", "elemer");
    Name name3=createName("bala","lajos");
//    printf("%i\n", compareName(name1, name2));
//    printf("%s\n", nameToStr(name1));
//    printf("%s\n", nameToStr(name2));
    Array res;
    res=createArray();
    addName(&res,name1);
    addName(&res,name2);
    addName(&res,name3);
    listName(&res);
    deleteName(&res,name2);
    printf("After deleteArray:\n");
    listName(&res);
    printf("SearchArray:%i\n\n\n",findName(&res,name1));
    hash table;
    table=createTable(10);
    insertTable(&table, name1);
    insertTable(&table, name2);
    insertTable(&table, name3);
    listTable(&table);
    printf("\nSearchHash:%i\n", searchHash(&table, name1));
    deleteHash(&table,name2);
    printf("After deleteHash:\n");
    listTable(&table);


    return 0;
}
