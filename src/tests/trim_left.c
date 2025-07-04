#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sstrings.h"

int main() {
    SString *only_spaces = CStringToSSTring("           ");
    SString *null = trim_left(only_spaces);
    if (null != NULL) {
        printf("Strings with only spaces should be NULL after trim\n");
        return 0;
    }

    SString *without_extra_space = CStringToSSTring("without spaces on left");
    SString *trimed_str_1 = trim_left(without_extra_space);
    if (strcmp(trimed_str_1->string, "without spaces on left") == 0) {
        printf("OK - \"%s\"\n", trimed_str_1->string);
    } else {
        return 0;
        printf("Not OK - \"%s\"\n", trimed_str_1->string);
    }

    SString *with_extra_space = CStringToSSTring("        with spaces on left");
    SString *trimed_str_2 = trim_left(with_extra_space);
    if (strcmp(trimed_str_2->string, "with spaces on left") == 0) {
        printf("OK - \"%s\"\n", trimed_str_2->string);
        return 1;
    }
    printf("Not OK - \"%s\"\n", trimed_str_2->string);
    return 0;
}