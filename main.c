#include "name.h"

int main() {
    Name name1 = createName("first", "last");
    Name name2 = createName("firs", "last");
    printf("%i\n", compareName(name1, name2));
    printf("%s\n", nameToStr(name1));
    printf("%s\n", nameToStr(name2));
    return 0;
}
