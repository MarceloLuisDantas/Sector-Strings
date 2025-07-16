#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str1 = CStringToSSTring("Dromedario");
    
    // ========================================================================================
    SString *rep1 = replace(str1, "eda", "x");
    if (rep1->len != 8) {
        printf("Not Ok - Len should be 8, but got %d\n", rep1->len);
        return 0;
    }
    printf("Len Ok - 8\n");

    if (strcmp(SStringToCString(rep1), "Dromxrio") != 0) {
        printf("Not Ok - Should be \"Dromxrio\", but got \"%s\"\n", SStringToCString(rep1));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep1));

    // ========================================================================================
    SString *rep2 = replace(str1, "eda", "xedax");
    if (rep2->len != 12) {
        printf("Not Ok - Len should be 12, but got %d\n", rep2->len);
        return 0;
    }
    printf("Len Ok - 12\n");

    if (strcmp(SStringToCString(rep2), "Dromxedaxrio") != 0) {
        printf("Not Ok - Should be \"Dromxedaxrio\", but got \"%s\"\n", SStringToCString(rep2));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep2));

    // ========================================================================================
    SString *rep3 = replace(str1, "Dro", "x");
    if (rep3->len != 8) {
        printf("Not Ok - Len should be 8, but got %d\n", rep3->len);
        return 0;
    }
    printf("Len Ok - 8\n");

    if (strcmp(SStringToCString(rep3), "xmedario") != 0) {
        printf("Not Ok - Should be \"xmedario\", but got \"%s\"\n", SStringToCString(rep3));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep3));
    
    // ========================================================================================
    SString *rep4 = replace(str1, "Dro", "xDrox");
    if (rep4->len != 12) {
        printf("Not Ok - Len should be 12, but got %d\n", rep4->len);
        return 0;
    }
    printf("Len Ok - 12\n");

    if (strcmp(SStringToCString(rep4), "xDroxmedario") != 0) {
        printf("Not Ok - Should be \"xDroxmedario\", but got \"%s\"\n", SStringToCString(rep4));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep4));

    // ========================================================================================
    SString *rep5 = replace(str1, "io", "x");
    if (rep5->len != 9) {
        printf("Not Ok - Len should be 9, but got %d\n", rep5->len);
        return 0;
    }
    printf("Len Ok - 9\n");

    if (strcmp(SStringToCString(rep5), "Dromedarx") != 0) {
        printf("Not Ok - Should be \"Dromedarx\", but got \"%s\"\n", SStringToCString(rep5));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep5));
    
    // ========================================================================================
    SString *rep6 = replace(str1, "io", "xiox");
    if (rep6->len != 12) {
        printf("Not Ok - Len should be 12, but got %d\n", rep6->len);
        return 0;
    }
    printf("Len Ok - 12\n");
    
    if (strcmp(SStringToCString(rep6), "Dromedarxiox") != 0) {
        printf("Not Ok - Should be \"Dromedarxiox\", but got \"%s\"\n", SStringToCString(rep6));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep6));

    // ========================================================================================
    SString *rep7 = replace(str1, "io", "");
    if (rep7->len != 8) {
        printf("Not Ok - Len should be 8, but got %d\n", rep7->len);
        return 0;
    }
    printf("Len Ok - 8\n");

    if (strcmp(SStringToCString(rep7), "Dromedar") != 0) {
        printf("Not Ok - Should be \"Dromedar\", but got \"%s\"\n", SStringToCString(rep7));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep7));

    // ========================================================================================
    SString *rep8 = replace(str1, "D", "");
    if (rep8->len != 9) {
        printf("Not Ok - Len should be 9, but got %d\n", rep8->len);
        return 0;
    }
    printf("Len Ok - 9\n");

    if (strcmp(SStringToCString(rep8), "romedario") != 0) {
        printf("Not Ok - Should be \"romedario\", but got \"%s\"\n", SStringToCString(rep8));
        return 0;
    }
    printf("String Ok - \"%s\"\n", SStringToCString(rep8));

    return 1;
}