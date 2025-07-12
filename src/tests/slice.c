#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str = CStringToSSTring("foo bars");
    if (slice(str, 6, 3) != NULL) {
        printf("Not Ok - should be \"NULL\" when start > end\n");
        return 0;
    } else {
        printf("Ok - start > end\n");
    }

    SString *sslice = slice(str, 2, 5);
    if (strcmp(sslice->string, "o ba") != 0) {
        printf("Not Ok - should be \"o ba\", but gets \"%s\"\n", sslice->string);
        return 0;
    } else {
        printf("Ok - \"%s\"\n", sslice->string);
    }

    SString *one_char = slice(str, 2, 2);
    if (strcmp(one_char->string, "o") != 0) {
        printf("Not Ok - should be \"o\", but gets \"%s\"\n", one_char->string);
        return 0;
    } else {
        printf("Ok - \"%s\"\n", one_char->string);
    }

    SString *one_char2 = slice(str, 0, 0);
    if (strcmp(one_char2->string, "f") != 0) {
        printf("Not Ok - should be \"f\", but gets \"%s\"\n", one_char2->string);
        return 0;
    } else {
        printf("Ok - \"%s\"\n", one_char2->string);
    }

    SString *one_char3 = slice(str, 7, 7);
    if (strcmp(one_char3->string, "s") != 0) {
        printf("Not Ok - should be \"f\", but gets \"%s\"\n", one_char3->string);
        return 0;
    } else {
        printf("Ok - \"%s\"\n", one_char3->string);
    }

    return 1;
}