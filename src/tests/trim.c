#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *only_spaces = CStringToSSTring("           ");
    SString *null = trim_right(only_spaces);
    if (null != NULL) {
        printf("Strings with only spaces should be NULL after trim\n");
        return 0;
    }

    SString *without_extra_space = CStringToSSTring("without extra spaces");
    SString *trimed_no_spaces = trim(without_extra_space);
    if (strcmp(trimed_no_spaces->string, "without extra spaces") == 0) {
        printf("OK - \"%s\"\n", trimed_no_spaces->string);
    } else {
        printf("Not OK - \"%s\"\n", trimed_no_spaces->string);
        return 0;
    }

    SString *with_extra_space_right = CStringToSSTring("with spaces on right        ");
    SString *trimed_right = trim(with_extra_space_right);
    if (strcmp(trimed_right->string, "with spaces on right") == 0) {
        printf("OK - \"%s\"\n", trimed_right->string);
    } else {
        printf("Not OK - \"%s\"\n", trimed_right->string);
    }
    
    SString *with_extra_space_left = CStringToSSTring("        with spaces on left");
    SString *trimed_left = trim(with_extra_space_left);
    if (strcmp(trimed_left->string, "with spaces on left") == 0) {
        printf("OK - \"%s\"\n", trimed_left->string);
        return 1;
    }
    printf("Not OK - \"%s\"\n", trimed_left->string);
    return 0;
}