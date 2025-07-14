#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *str_1 = CStringToSSTring("foo bar baz");
    SStringArray *array_1 = split(str_1, ' ');
    if (array_1->len != 3) {
        printf("Not Ok - len should be 3, but got %ld\n", array_1->len);
        return 0;
    } else {
        printf("OK len equals 3\n");
    }
    
    if (strcmp(SStringToCString(array_1->strings[0]), "foo") != 0) {
        printf("Not Ok - frist element should be \"foo\", but got \"%s\"\n", SStringToCString(array_1->strings[0]));
        return 0;
    } else {
        printf("First Element Ok, \"foo\"\n");
    }

    if (strcmp(SStringToCString(array_1->strings[1]), "bar") != 0) {
        printf("Not Ok - frist element should be \"bar\", but got \"%s\"\n", SStringToCString(array_1->strings[1]));
        return 0;
    } else {
        printf("First Element Ok, \"bar\"\n");
    }

    if (strcmp(SStringToCString(array_1->strings[2]), "baz") != 0) {
        printf("Not Ok - frist element should be \"baz\", but got \"%s\"\n", SStringToCString(array_1->strings[2]));
        return 0;
    } else {
        printf("First Element Ok, \"baz\"\n");
    }

    SString *str_2 = CStringToSSTring("foobarbaz");
    SStringArray *array_2 = split(str_2, ' ');
    if (array_2->len != 1) {
        printf("Not Ok - len should be 1, but got '%ld\n", array_2->len);
        return 0;
    } else {
        printf("OK len equals 3\n");
    }

    if (strcmp(SStringToCString(array_2->strings[0]), "foobarbaz") != 0) {
        printf("Not Ok - frist element should be \"foobarbaz\", but got \"%s\"\n", SStringToCString(array_2->strings[0]));
        return 0;
    } else {
        printf("First Element Ok, \"foobarbaz\"\n");
    }

    SString *str_3 = CStringToSSTring("aaaaaaaaaa");
    SStringArray *array_3 = split(str_3, 'a');
    if (array_3->len != 11) {
        printf("Not Ok - len should be 11, but got '%ld\n", array_3->len);
        return 0;
    } else {
        printf("OK len equals 3\n");
    }

    for (int i = 0; i < array_3->len; i++) {
        if (strcmp(SStringToCString(array_3->strings[i]), "") != 0) {
            printf("Not Ok - All values in array3 should be empty strings, but got \"%s\" in index '%d\n", SStringToCString(array_3->strings[i]), i);
            return 0;
        }
    }
    printf("Ok, all strings in array_3 are empty\n");

    return 1;
}