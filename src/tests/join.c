#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SStringArray *array = split(CStringToSSTring("foo bar baz"), ' ');
    SString *joined_1 = join(array, " ");
    if (joined_1->len != 11) {
        printf("Not Ok - len should be 11, but got %ld\n", joined_1->len);
        return 0;
    }
    printf("Len OK\n");

    if (strcmp(SStringToCString(joined_1), "foo bar baz") != 0) {
        printf("Not Ok - Should be \"foo bar baz\", but got \"%s\"\n", SStringToCString(joined_1));
        return 0;
    }
    printf("Joined OK - \"%s\"\n", SStringToCString(joined_1));

    SString *joined_2 = join(array, "--");
    if (joined_2->len != 13) {
        printf("Not Ok - len should be 13, but got %ld\n", joined_2->len);
        return 0;
    }
    printf("Len OK\n");

    if (strcmp(SStringToCString(joined_2), "foo--bar--baz") != 0) {
        printf("Not Ok - Should be \"foo--bar--baz\", but got \"%s\"\n", SStringToCString(joined_2));
        return 0;
    }
    printf("Joined OK - \"%s\"\n", SStringToCString(joined_2));
    
    SStringArray *array2 = split(CStringToSSTring("aaaaaaaaaa"), 'a');
    SString *joined_3 = join(array2, " ");
    if (joined_3->len != 10) {
        printf("Not Ok - len should be 10, but got %ld\n", joined_3->len);
        return 0;
    }
    printf("Len OK\n");

    if (strcmp(SStringToCString(joined_3), "          ") != 0) {
        printf("Not Ok - Should be \"foo bar baz\", but got \"%s\"\n", SStringToCString(joined_3));
        return 0;
    }
    printf("Joined OK - \"%s\"\n", SStringToCString(joined_3));

    SStringArray *array3 = split(CStringToSSTring("dromedario"), 'z');
    SString *joined_4 = join(array3, " ");
    if (joined_4->len != 10) {
        printf("Not Ok - len should be 10, but got %ld\n", joined_4->len);
        return 0;
    }
    printf("Len OK\n");

    if (strcmp(SStringToCString(joined_4), "dromedario") != 0) {
        printf("Not Ok - Should be \"dromedario\", but got \"%s\"\n", SStringToCString(joined_4));
        return 0;
    }
    printf("Joined OK - \"%s\"\n", SStringToCString(joined_4));

    SStringArray *array4 = split(CStringToSSTring(""), 'z');
    SString *joined_5 = join(array4, " ");
    if (joined_5->len != 0) {
        printf("Not Ok - len should be 0, but got %ld\n", joined_5->len);
        return 0;
    }
    printf("Len OK\n");

    if (strcmp(SStringToCString(joined_5), "") != 0) {
        printf("Not Ok - Should be \"\", but got \"%s\"\n", SStringToCString(joined_5));
        return 0;
    }
    printf("Joined OK - \"%s\"\n", SStringToCString(joined_5));

    return 1;
}