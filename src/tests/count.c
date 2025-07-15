#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str0 = CStringToSSTring("camel");
    size_t total0 = count(str0, "dromedario");
    if (total0 != -1) {
        printf("Not Ok, total should -1, but got %d\n", total0);
        return 0;
    }
    printf("Total Ok, -1.\n");

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

    SString *str5 = CStringToSSTring("aaaaabbbaa");
    size_t total5 = count(str5, "a");
    if (total5 != 7) {
        printf("Not Ok, total should 7, but got %d\n", total5);
        return 0;
    }
    printf("Total Ok, 7.\n");

    SString *str6 = CStringToSSTring("aaaaabbbaac");
    size_t total6 = count(str6, "c");
    if (total6 != 1) {
        printf("Not Ok, total should 1, but got %d\n", total6);
        return 0;
    }
    printf("Total Ok, 1.\n");

    return 1;
}