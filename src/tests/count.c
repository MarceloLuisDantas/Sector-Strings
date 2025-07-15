#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("dromedario");
    size_t total1 = count(str1, "eda");
    if (total1 != 1) {
        printf("Not Ok, total should 1, but got %d\n", total1);
        return 0;
    }
    printf("Total Ok, 1.\n");

    SString *str2 = CStringToSSTring("fooafoodfoofoo");
    size_t total2 = count(str2, "foo");
    if (total2 != 4) {
        printf("Not Ok, total should 4, but got %d\n", total2);
        return 0;
    }
    printf("Total Ok, 4.\n");

    SString *str3 = CStringToSSTring("bar");
    size_t total3 = count(str3, "bar");
    if (total3 != 1) {
        printf("Not Ok, total should 1, but got %d\n", total3);
        return 0;
    }
    printf("Total Ok, 1.\n");

    SString *str4 = CStringToSSTring("bar");
    size_t total4 = count(str4, "fo");
    if (total4 != 0) {
        printf("Not Ok, total should 0, but got %d\n", total4);
        return 0;
    }
    printf("Total Ok, 0.\n");

    return 1;
}