#include "name.h"
#include "linked_list.h"

#define endl printf("\n")

int main() {
    Node *root = NULL;
    insertList(&root, createName("First", "Name"));
    insertList(&root, createName("2nd", "Name"));
    insertList(&root, createName("3rd", "Name"));
    utilPrintList(root);
    endl;
    deleteFromList(&root, createName("2nd", "Name"));
    utilPrintList(root);
    endl;
    deleteFromList(&root, createName("3rd", "Name"));
    utilPrintList(root);
    return 0;
}
