#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("dromedario");
    int index1 = indexof(str1, "eda");
    if (index1 != 4) {
        printf("Not Ok, index should 4, but got %d\n", index1);
        return 0;
    }
    printf("index Ok, 4.\n");

    SString *str2 = CStringToSSTring("fooafoodfoofoo");
    int index2 = indexof(str2, "foo");
    if (index2 != 0) {
        printf("Not Ok, index should 0, but got %d\n", index2);
        return 0;
    }
    printf("index Ok, 0.\n");

    SString *str3 = CStringToSSTring("asdfbar");
    int index3 = indexof(str3, "bar");
    if (index3 != 4) {
        printf("Not Ok, index should 4, but got %d\n", index3);
        return 0;
    }
    printf("index Ok, 5.\n");

    SString *str4 = CStringToSSTring("bar");
    int index4 = indexof(str4, "r");
    if (index4 != 2) {
        printf("Not Ok, index should 2, but got %d\n", index4);
        return 0;
    }
    printf("index Ok, 2.\n");

    SString *str5 = CStringToSSTring("aaaaabbbaa");
    int index5 = indexof(str5, "c");
    if (index5 != -1) {
        printf("Not Ok, index should -1, but got %d\n", index5);
        return 0;
    }
    printf("index Ok, -1.\n");

    return 1;
}